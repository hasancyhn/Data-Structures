// HASAN CEYHAN 20010011091
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
};

struct node * kokDugumOlustur(int veri){
	struct node * root = (struct node*) malloc(sizeof(struct node));
	
	root->data  = veri;
	root->left  = NULL;
	root->right = NULL;
	return root;
}

struct node * elemanEkle(struct node * root, int veri){
	if(root == NULL){
		root = kokDugumOlustur(veri);
	}
	else{
		if(veri < root->data){
			root->left = elemanEkle(root->left, veri);
		}
		else{	// veri buyukse
			root->right = elemanEkle(root->right, veri);
		}
	}
	return root;
}

int enKucukVeri(struct node * root){
	struct node * temp = root;
	if(root ==NULL){
		return 0;
	}
	else{
		while(temp->left != NULL){
			temp = temp->left;
		}
		return temp->data;
	}
}

int enBuyukVeri(struct node * root){
	struct node * temp = root;
	if(root ==NULL){
		return 0;
	}
	else{
		while(temp->right != NULL){
			temp = temp->right;
		}
		return temp->data;
	}
}

struct node * elemanSil(struct node * root, int silmekIstenilenEleman){
    if(root == NULL){	// Eger veri yoksa NULL dondur
        return NULL;
	}
    if(root->data == silmekIstenilenEleman){	// Eger silinecek veri agacta bulunduysa
        // Silinecek degerin hem sol hem sagi null ise dugum yok direk silinir
        if(root->left == NULL && root->right == NULL){
            return NULL;
    	}
        // Silinecek degerin saginda dugum varsa, sagda en kucugu silincek deger bulunur
        if(root->right != NULL){	// Deger bulundu ve sag tarafi NULL degil
            root->data = enKucukVeri(root->right);	// Sagdaki en kucuk degeri al
            // Tasidigimiz minumum deger agacta iki tane oldu, en ucta olan eskisini siliyoruz
            root->right = elemanSil(root->right, enKucukVeri(root->right));
            return root;
        }
        // Agacin sagi da null ise dugum yoksa; soldaki en buyuk degeri silincekle degistircez
        root->data = enBuyukVeri(root->left);
        // Tasidigimiz minumum deger agacta ikitane oldu, en ucta olan eskisini siliyoruz
        root->left = elemanSil(root->left, enBuyukVeri(root->left));	// Soldaki en buyuk degeri al
        return root;
    }
    // Sag ve sol degeri arama
    if(root->data < silmekIstenilenEleman){	// Deger henuz bulunmadi, silmekIstenilenEleman degeri kucukse sol agacta ara
        root->right = elemanSil(root->right, silmekIstenilenEleman);
        return root;
    }
    root->left = elemanSil(root->left, silmekIstenilenEleman);	// Deger henuz bulunmadi, silmekIstenilenEleman degeri buyukse sag agacta ara
    return root;
}

void inorder(struct node * root){	// kok ortada
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int dugumSayisi(struct node * root){
	if(root == NULL){
		return 0;
	}
	else{
		return dugumSayisi(root->left) + 1 + dugumSayisi(root->right);
	}
}

int yukseklik(struct node * root){
	int solYukseklik, sagYukseklik;
	if(root == NULL){
		return 0;
	}
	else{
		solYukseklik = yukseklik(root->left);
		sagYukseklik = yukseklik(root->right);
		if(sagYukseklik>solYukseklik){
			return sagYukseklik+1;
		}
		else{
			return solYukseklik+1;
		}
	}
}

int fullBinaryKontrol(struct node * root){
    if (root == NULL){
        return 0;
	}
    // yaprak dugum kontrolu
    if (root->left == NULL && root->right == NULL){
        return 1;
	}
	// Hem sol hem de sag NULL deðilse ayrýca sol ve sag alt agaclar doluysa
    if ((root->left) && (root->right)){
        return (fullBinaryKontrol(root->left) && fullBinaryKontrol(root->right));
	}
    return 0;
}

int completeBinaryKontrol(struct node * root, int indeks, int dugumSayisi){
    if (root == NULL){
        return 1;
	}
    if (indeks >= dugumSayisi){
        return 0;
	}
    return (completeBinaryKontrol(root->left, 2*indeks+1, dugumSayisi) && completeBinaryKontrol(root->right, 2*indeks+2, dugumSayisi));
}
/*
void preorder(struct node * root){	// kok basta
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node * root){	// kok sonda
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}*/

int main (){	
	struct node * eleman = NULL;

	while(1){
		int sayi, secim;
		printf("\n*************MENU*************");
		printf("\nEklemek Icin ----------------> 1\n");
		printf("Agactan Veri Silmek Icin ----> 2\n");
		printf("Dugum Sayisi Icin -----------> 3\n");
		printf("Yukseklik Icin --------------> 4\n");
		printf("En Kucuk Veri Icin ----------> 5\n");
		printf("En Buyuk Veri Icin ----------> 6\n");
		printf("Inorder Ile Siralamak Icin --> 7\n");
		printf("Full ve Complete Binary Icin-> 8\n");
		printf("Cikis Icin ------------------> 0\n");
		printf("Seciminizi Yapin: ");	scanf("%d", &secim);
		switch(secim){
			case 1: printf("\n\nSayi Giriniz: ");	scanf("%d", &sayi);
					eleman = elemanEkle(eleman, sayi);
					break;
			case 2:	printf("\n\nSilmek Istediginiz Elemani Giriniz: ");	scanf("%d", &sayi);
					eleman = elemanSil(eleman, sayi);
					break;
			case 3: system("cls");
					sayi = dugumSayisi(eleman);
					printf("Dugum Sayisi: %d", sayi);
					break;
			case 4: system("cls");
					sayi = yukseklik(eleman);
					printf("Yukseklik: %d",sayi);
					break;
			case 5: system("cls");
					sayi = enKucukVeri(eleman);
					printf("En Kucuk Veri: %d\n", sayi);
					break;
			case 6: system("cls");
					sayi = enBuyukVeri(eleman);
					printf("En Buyuk Veri: %d\n", sayi);
					break;
			case 7: system("cls");
					inorder(eleman);
					break;
			case 8: if(fullBinaryKontrol(eleman)){
        				printf("\nAgac yapimiz full binary'dir.\n");
					}
					else{
        				printf("\nAgac yapimiz full binary degildir.\n");
    				}
    				if(completeBinaryKontrol(eleman, 0, dugumSayisi(eleman))){
        				printf("Agac yapimiz complete binary'dir.\n");
    				}
    				else{
        				printf("Agac yapimiz complete binary degildir.\n");
    				}
    				break;
			case 0: printf("\nCikis Saglandi!");
					return 0;
			default: printf("Hatali Veri Girisi!\n");
		}	
	}
/*
	printf("\nPREORDER:  ");		preorder(eleman);
	printf("\nINORDER:   ");		inorder(eleman);
	printf("\nPOSTORDER: ");		postorder(eleman);
*/	
	return 0;
}
