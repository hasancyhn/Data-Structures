// HASAN CEYHAN 20010011091

// 2 1 7 4 5 3 8 -> EKLE
// 4 2 1 3 7 5 8 -> SIRALA
// 3 -------------> SIL
// 4 2 1 7 5 8 ---> SIRALA


// 10 15 9 12 13 79 45 36 22 -> EKLE
// 13 10 9 12 45 22 15 36 79 -> SIRALA
// 45 ------------------------> SIL
// 17 ------------------------> EKLE
// 13 10 9 12 22 15 17 79 36 -> SIRALA
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *sol;
	struct node *sag;
	int yukseklik;
};

struct node *kokDugumOlustur(int veri){
	struct node *root = (struct node *) malloc(sizeof(struct node));
	root->data = veri;
	root->sol = NULL;
	root->sag = NULL;
	root->yukseklik = 1;
	return (root);
}

int yukseklik(struct node *root) {
	if (root == NULL){
    	return 0;
	}
	return root->yukseklik;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

struct node *sagaDondur(struct node *y) {
	struct node *x = y->sol;
	struct node *T2 = x->sag;
	
	x->sag = y;
	y->sol = T2;

	y->yukseklik = max(yukseklik(y->sol), yukseklik(y->sag)) + 1;
	x->yukseklik = max(yukseklik(x->sol), yukseklik(x->sag)) + 1;
	return x;
}

struct node *solaDondur(struct node *x){
	struct node *y = x->sag;
	struct node *T2 = y->sol;

	y->sol = x;
	x->sag = T2;

	x->yukseklik = max(yukseklik(x->sol), yukseklik(x->sag)) + 1;
	y->yukseklik = max(yukseklik(y->sol), yukseklik(y->sag)) + 1;
	return y;
}

// Denge saglanir.
int getBalance(struct node *root) {
	if (root == NULL){
		return 0;
	}
	return yukseklik(root->sol) - yukseklik(root->sag);
}


struct node *elemanEkle(struct node *root, int veri) {
	// Dugum bos mu kontrol edilir.
	if (root == NULL){
		return (kokDugumOlustur(veri));
	}

	if (veri < root->data){
		root->sol = elemanEkle(root->sol, veri);
	}
	else if (veri > root->data){
		root->sag = elemanEkle(root->sag, veri);
	}
	else{
		return root;
	}

	// Her dugumun denge faktoru guncellenir ve agaci dengeli hale getirilir.
	root->yukseklik = 1 + max(yukseklik(root->sol), yukseklik(root->sag));

	int balance = getBalance(root);
	if (balance > 1 && veri < root->sol->data){
		return sagaDondur(root);
	}

	if (balance < -1 && veri > root->sag->data){
		return solaDondur(root);
	}

	if (balance > 1 && veri > root->sol->data){
		root->sol = solaDondur(root->sol);
		return sagaDondur(root);
	}

	if (balance < -1 && veri < root->sag->data){
		root->sag = sagaDondur(root->sag);
		return solaDondur(root);
	}
  return root;
}

struct node *minValueNode(struct node *root) {
	struct node *current = root;

	while (current->sol != NULL){
		current = current->sol;
	}
	return current;
}

// Dugum silme
struct node *elemanSil(struct node *root, int silmekIstenilenEleman) {
	// Aranan dugum yoksa
	if (root == NULL){
		return root;
	}

	if (silmekIstenilenEleman < root->data){
		root->sol = elemanSil(root->sol, silmekIstenilenEleman);
	}
	else if (silmekIstenilenEleman > root->data){
		root->sag = elemanSil(root->sag, silmekIstenilenEleman);
	}
	else{
		if ((root->sol == NULL) || (root->sag == NULL)){
			struct node *temp = root->sol ? root->sol : root->sag;
			if (temp == NULL){
				temp = root;
				root = NULL;
			}
			else{
				*root = *temp;
			}
			free(temp);
    	}
		else{
			struct node *temp = minValueNode(root->sag);
			root->data = temp->data;
			root->sag = elemanSil(root->sag, temp->data);
    	}
	}
	if(root == NULL){
		return root;
	}
	
	// Her dugumun denge faktoru guncellenir ve agaci dengeli hale getirilir.
	root->yukseklik = 1 + max(yukseklik(root->sol), yukseklik(root->sag));

	int balance = getBalance(root);
	if(balance > 1 && getBalance(root->sol) >= 0){
		return sagaDondur(root);
	}
	if(balance > 1 && getBalance(root->sol) < 0){
		root->sol = solaDondur(root->sol);
		return sagaDondur(root);
	}

	if(balance < -1 && getBalance(root->sag) <= 0){
		return solaDondur(root);
	}

	if(balance < -1 && getBalance(root->sag) > 0){
		root->sag = sagaDondur(root->sag);
		return solaDondur(root);
	}
  return root;
}


void ekranaYazdir(struct node *root) {
	if (root != NULL) {
		printf("%d ", root->data);
		ekranaYazdir(root->sol);
		ekranaYazdir(root->sag);
	}
}

int main() {
	struct node *eleman = NULL;
	
	while(1){
		int sayi, secim;
		printf("\n********************MENU********************");
		printf("\nEklemek Icin -----------------------------> 1\n");
		printf("Agactan Veri Silmek Icin -----------------> 2\n");
		printf("Ekrana Preorder Ile Yazdirmak Icin -------> 3\n");
		printf("Cikis Icin -------------------------------> 0\n");
		printf("Seciminizi Yapin: ");	scanf("%d", &secim);
		switch(secim){
			case 1: printf("\n\nSayi Giriniz: ");	scanf("%d", &sayi);
					eleman = elemanEkle(eleman, sayi);
					break;
			case 2:	printf("\n\nSilmek Istediginiz Elemani Giriniz: ");	scanf("%d", &sayi);
					eleman = elemanSil(eleman, sayi);
					break;
			case 3: system("cls");
					ekranaYazdir(eleman);
					break;
			case 0: printf("\nCikis Saglandi!");
					return 0;
			default: printf("Hatali Veri Girisi!\n");
		}	
	}
// 2 1 7 4 5 3 8 -> EKLE
// 4 2 1 3 7 5 8 -> SIRALA
// 3 -------------> SIL
// 4 2 1 7 5 8 ---> SIRALA


// 10 15 9 12 13 79 45 36 22 -> EKLE
// 13 10 9 12 45 22 15 36 79 -> SIRALA
// 45 ------------------------> SIL
// 17 ------------------------> EKLE
// 13 10 9 12 22 15 17 79 36 -> SIRALA
	return 0;
}
