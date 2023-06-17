// 20010011091 Hasan CEYHAN Odev-5 (2-3 Tree)
#include <iostream>
using namespace std;

struct TreeNode {
    int keys[2];
    TreeNode* children[3];
    int numKeys;
    bool leaf;

    TreeNode(bool isLeaf) {
        numKeys = 0;
        leaf = isLeaf;
        for (int i = 0; i < 3; i++) {
            children[i] = nullptr;
        }
    }
};

class TwoThreeTree {
private:
    TreeNode* root;

public:
    TwoThreeTree() {
        root = nullptr;
    }

    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(true);
            root->keys[0] = value;
            root->numKeys = 1;
        } else {
            if (root->numKeys == 2) {
                TreeNode* newNode = new TreeNode(false);
                newNode->children[0] = root;
                splitChild(newNode, 0, root);
                insertNonFull(newNode, value);
                root = newNode;
            } else {
                insertNonFull(root, value);
            }
        }
    }

    void insertNonFull(TreeNode* node, int value) {
        int i = node->numKeys - 1;
        if (node->leaf) {
            while (i >= 0 && value < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = value;
            node->numKeys++;
        } else {
            while (i >= 0 && value < node->keys[i]) {
                i--;
            }
            i++;
            if (node->children[i]->numKeys == 2) {
                splitChild(node, i, node->children[i]);
                if (value > node->keys[i]) {
                    i++;
                }
            }
            insertNonFull(node->children[i], value);
        }
    }

    void splitChild(TreeNode* parentNode, int index, TreeNode* childNode) {
        TreeNode* newNode = new TreeNode(childNode->leaf);
        newNode->numKeys = 1;
        newNode->keys[0] = childNode->keys[2];

        if (!childNode->leaf) {
            newNode->children[0] = childNode->children[2];
            newNode->children[1] = childNode->children[3];
        }

        childNode->numKeys = 1;

        for (int i = parentNode->numKeys; i > index; i--) {
            parentNode->children[i + 1] = parentNode->children[i];
        }
        parentNode->children[index + 1] = newNode;

        for (int i = parentNode->numKeys - 1; i >= index; i--) {
            parentNode->keys[i + 1] = parentNode->keys[i];
        }
        parentNode->keys[index] = childNode->keys[1];
        parentNode->numKeys++;
    }

    void remove(int value) {
        if (root == nullptr) {
            cout << "Agac bos!" << endl;
            return;
        }

        removeValue(root, value);

        if (root->numKeys == 0) {
            TreeNode* oldRoot = root;
            if (root->leaf) {
                root = nullptr;
            }
			else {
                root = root->children[0];
            }
            delete oldRoot;
        }
    }

    void removeValue(TreeNode* node, int value) {
        int i = 0;
        while (i < node->numKeys && value > node->keys[i]) {
            i++;
        }

        if (i < node->numKeys && value == node->keys[i]) {
            if (node->leaf) {
                for (int j = i; j < node->numKeys - 1; j++) {
                    node->keys[j] = node->keys[j + 1];
                }
                node->numKeys--;
            }
			else {
                TreeNode* predecessor = node->children[i];
                TreeNode* successor = node->children[i + 1];

                if (predecessor->numKeys >= 2) {
                    int predValue = getPredecessor(predecessor);
                    removeValue(predecessor, predValue);
                    node->keys[i] = predValue;
                }
				else if (successor->numKeys >= 2) {
                    int succValue = getSuccessor(successor);
                    removeValue(successor, succValue);
                    node->keys[i] = succValue;
                }
				else {
                    mergeChildren(node, i, predecessor, successor);
                    removeValue(predecessor, value);
                }
            }
        }
		else {
            if (node->leaf) {
                cout << "Eleman bulunamadi!" << endl;
                return;
            }

            TreeNode* child = node->children[i];
            if (child->numKeys == 1) {
                TreeNode* leftSibling = (i > 0) ? node->children[i - 1] : nullptr;
                TreeNode* rightSibling = (i < node->numKeys) ? node->children[i + 1] : nullptr;

                if (leftSibling && leftSibling->numKeys >= 2) {
                    borrowFromLeftSibling(node, i, child, leftSibling);
                }
				else if (rightSibling && rightSibling->numKeys >= 2) {
                    borrowFromRightSibling(node, i, child, rightSibling);
                }
				else if (leftSibling) {
                    mergeChildren(node, i - 1, leftSibling, child);
                    child = leftSibling;
                }
				else if (rightSibling) {
                    mergeChildren(node, i, child, rightSibling);
                }
            }
            removeValue(child, value);
        }
    }

    int getPredecessor(TreeNode* node) {
        while (!node->leaf) {
            node = node->children[node->numKeys];
        }
        return node->keys[node->numKeys - 1];
    }

    int getSuccessor(TreeNode* node) {
        while (!node->leaf) {
            node = node->children[0];
        }
        return node->keys[0];
    }

    void borrowFromLeftSibling(TreeNode* parentNode, int index, TreeNode* node, TreeNode* leftSibling) {
        for (int i = node->numKeys - 1; i >= 0; i--) {
            node->keys[i + 1] = node->keys[i];
        }
        node->keys[0] = parentNode->keys[index - 1];

        if (!node->leaf) {
            for (int i = node->numKeys; i >= 0; i--) {
                node->children[i + 1] = node->children[i];
            }
            node->children[0] = leftSibling->children[leftSibling->numKeys];
        }

        node->numKeys++;
        parentNode->keys[index - 1] = leftSibling->keys[leftSibling->numKeys - 1];
        leftSibling->numKeys--;
    }

    void borrowFromRightSibling(TreeNode* parentNode, int index, TreeNode* node, TreeNode* rightSibling) {
        node->keys[node->numKeys] = parentNode->keys[index];

        if (!node->leaf) {
            node->children[node->numKeys + 1] = rightSibling->children[0];
        }

        node->numKeys++;
        parentNode->keys[index] = rightSibling->keys[0];
        rightSibling->numKeys--;

        for (int i = 0; i < rightSibling->numKeys; i++) {
            rightSibling->keys[i] = rightSibling->keys[i + 1];
        }

        if (!rightSibling->leaf) {
            for (int i = 0; i <= rightSibling->numKeys; i++) {
                rightSibling->children[i] = rightSibling->children[i + 1];
            }
        }
    }

    void mergeChildren(TreeNode* parentNode, int index, TreeNode* leftChild, TreeNode* rightChild) {
        leftChild->keys[1] = parentNode->keys[index];
        leftChild->numKeys = 2;

        for (int i = 0; i < rightChild->numKeys; i++) {
            leftChild->keys[i + 2] = rightChild->keys[i];
        }

        if (!leftChild->leaf) {
            for (int i = 0; i <= rightChild->numKeys; i++) {
                leftChild->children[i + 2] = rightChild->children[i];
            }
        }

        for (int i = index; i < parentNode->numKeys - 1; i++) {
            parentNode->keys[i] = parentNode->keys[i + 1];
        }

        for (int i = index + 1; i < parentNode->numKeys; i++) {
            parentNode->children[i] = parentNode->children[i + 1];
        }

        parentNode->numKeys--;
        delete rightChild;
    }

    void print() {
        if (root != nullptr) {
            printTree(root);
        }
		else {
            cout << "Agac bos!" << endl;
        }
    }

    void printTree(TreeNode* node) {
        for (int i = 0; i < node->numKeys; i++) {
            cout << node->keys[i] << " ";
        }
        cout << endl;

        if (!node->leaf) {
            for (int i = 0; i <= node->numKeys; i++) {
                printTree(node->children[i]);
            }
        }
    }
};

int main() {
    TwoThreeTree tree;
    int choice, value;

    while (true) {
        cout << "1. Eleman ekle\n";
        cout << "2. Eleman sil\n";
        cout << "3. Agaci yazdir\n";
        cout << "4. Cikis\n";
        cout << "Seciminizi yapin: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Eklenecek elemani girin: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Silinecek elemani girin: ";
                cin >> value;
                tree.remove(value);
                break;
            case 3:
                tree.print();
                break;
            case 4:
                exit(0);
            default:
                cout << "Gecersiz secim!" << endl;
        }
    }
}
