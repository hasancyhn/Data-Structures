This code is a C++ program that represents a 2-3 tree data structure. It allows for insertion, deletion, and printing operations on the tree. Here are the functions:

1- insert(int value): Inserts the specified value into the tree.
2- insertNonFull(TreeNode* node, int value): Performs an insertion of a value into the specified node when it is not full.
3- splitChild(TreeNode* parentNode, int index, TreeNode* childNode): Splits the child at the specified index of the parent node into two.
4- remove(int value): Removes the specified value from the tree.
5- removeValue(TreeNode* node, int value): Removes the specified value from the given node.
6- getPredecessor(TreeNode* node): Finds the predecessor of a value in the specified node.
7- getSuccessor(TreeNode* node): Finds the successor of a value in the specified node.
8- borrowFromLeftSibling(TreeNode* parentNode, int index, TreeNode* node, TreeNode* leftSibling): Borrows a value from the left sibling.
9- borrowFromRightSibling(TreeNode* parentNode, int index, TreeNode* node, TreeNode* rightSibling): Borrows a value from the right sibling.
10- mergeChildren(TreeNode* parentNode, int index, TreeNode* leftChild, TreeNode* rightChild): Merges two children into one.
11- print(): Prints the tree.
12- printTree(TreeNode* node): Prints the specified node and its sub-nodes.
The main function presents a menu to the user and performs the corresponding operations based on the user's choice. The user can add elements, delete elements, and print the tree. The program continues to run until the user chooses to exit.
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
Bu kod, 2-3 ağaç (2-3 tree) yapısını temsil eden bir C++ programıdır. Ağaç üzerinde ekleme, silme ve yazdırma işlemlerini gerçekleştirebilirsiniz. İşlevler şunlardır:

1- insert(int value): Belirtilen değeri ağaca ekler.
2- insertNonFull(TreeNode* node, int value): Belirtilen düğümün dolu olmayan durumda bir değer eklemesini gerçekleştirir.
3- splitChild(TreeNode* parentNode, int index, TreeNode* childNode): Belirtilen düğümün, belirtilen endeksteki çocuğunu ikiye böler.
4- remove(int value): Belirtilen değeri ağaçtan siler.
5- removeValue(TreeNode* node, int value): Belirtilen düğümde, belirtilen değeri siler.
6- getPredecessor(TreeNode* node): Belirtilen düğümdeki bir değerin öncülünü bulur.
7- getSuccessor(TreeNode* node): Belirtilen düğümdeki bir değerin halefini bulur.
8- borrowFromLeftSibling(TreeNode* parentNode, int index, TreeNode* node, TreeNode* leftSibling): Sol kardeşten bir değer alır.
9- borrowFromRightSibling(TreeNode* parentNode, int index, TreeNode* node, TreeNode* rightSibling): Sağ kardeşten bir değer alır.
10 mergeChildren(TreeNode* parentNode, int index, TreeNode* leftChild, TreeNode* rightChild): İki çocuğu birleştirir.
11- print(): Ağacı yazdırır.
12- printTree(TreeNode* node): Belirtilen düğüm ve alt düğümlerini yazdırır.
Ana fonksiyon, kullanıcıya bir menü sunar ve kullanıcının seçimine göre ilgili işlemleri gerçekleştirir. Kullanıcı eleman ekleyebilir, eleman silebilir ve ağacı yazdırabilir. Menüden çıkış yapılıncaya kadar program çalışmaya devam eder.