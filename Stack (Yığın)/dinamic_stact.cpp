// DINAMIC STACK

#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum * sonraki;
};

struct dugum * temp = NULL;
struct dugum * top  = NULL;	// En üstteki degeri, top degiskeni tutar.

void push(int kullanicininGirdigiSayi){
	struct dugum *eleman = (struct dugum*) malloc(sizeof(struct dugum));
	eleman->veri = kullanicininGirdigiSayi;
	
	// Yiginda hic eleman yoksa if bloguna girip elemani ekleriz.
	if(top == NULL){
		top = eleman;
		top->sonraki = NULL;
	}
	else{
		eleman->sonraki = top;
		top = eleman;
	}
}

void pop(){
	if (top == NULL){
		printf("\nYigin bos! Cikartilacak Eleman Yok.\n");
	}
	// Yigindan cikaracagimiz eleman top'dýr.
	else{
		printf("\n%d Elemani Yigindan Cikarildi.\n", top->veri);
		temp = top->sonraki;
		free(top);
		top = temp;
	}
}

void ekranaYazdir(){
	system("cls");
	if(top == NULL){
		printf("\nYigin bos!\n");
	}
	else{
		temp = top;
		while(temp->sonraki != NULL){
			printf("%d \n", temp->veri);
			temp = temp->sonraki;
		}
		printf("%d \n", temp->veri);
	}
}

void peek(){
	if(top == NULL){
		printf("\nYigin bos!\n");
	}
	else{
		printf("\nYiginin En Ustteki Elemani: %d \n", top->veri);
	}
}

int main (){
	int secim, sayi;
	while(1){
		printf("\n---------DINAMIC STACK--------\n");
		printf("Eleman Eklemek Icin  (PUSH) ----> 1\n");
		printf("Eleman Cikarmak Icin (POP)  ----> 2\n");
		printf("En Ustteki Eleman Icin (PEEK) --> 3\n");
		printf("Ekrana Yazdirmak Icin ----------> 4\n");
		printf("Cikis Icin ---------------------> 5\n");
		printf("Seciminizi Yapiniz: ");	scanf("%d", &secim);
		
		switch(secim){
			case 1:	printf("\nEklenecek Sayi: ");	scanf("%d", &sayi);
					push(sayi);
					break;
			case 2:	pop();
					break;
			case 3:	peek();
					break;
			case 4: ekranaYazdir();
					break;
			case 5:	exit(1);
					break;
		}
	}
}
