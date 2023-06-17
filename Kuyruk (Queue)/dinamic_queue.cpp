// DINAMIC QUEUE
#include <stdio.h>
#include <stdlib.h>

struct dugum {
	int veri;
	struct dugum * sonraki;
};

struct dugum * temp      = NULL;
struct dugum * ilkEleman = NULL;
struct dugum * sonEleman = NULL;


void elemanEkle(int kullanicininGirdigiVeri){
	struct dugum *eleman = (struct dugum*) malloc (sizeof( struct dugum));
	eleman->veri = kullanicininGirdigiVeri;
	
	// Kuyruk bossa if bloguna gireriz.
	if(ilkEleman == NULL){
		ilkEleman = eleman;
		ilkEleman->sonraki = ilkEleman;
		sonEleman = eleman;
		sonEleman->sonraki = NULL;
	}
	else{
		// Kuyrukta tek eleman yani tek dugum varsa if bloguna girer.
		if(ilkEleman->sonraki == ilkEleman){
			sonEleman->sonraki = eleman;
			sonEleman = eleman;
			sonEleman->sonraki = NULL;
			ilkEleman->sonraki = sonEleman;
		}
		else{
			sonEleman->sonraki = eleman;
			sonEleman = eleman;
			sonEleman->sonraki = NULL;
		}
	}
}

void elemanSil(){
	if(ilkEleman == NULL){
		printf("\nKuyruk bostur!\n");
	}
	else{
		printf("\n%d Elemani Kuyruktan Cikarildi.\n", ilkEleman->veri);
		// Silme islemi bastan yapilir.
		temp = ilkEleman->sonraki;
		free(ilkEleman);
		ilkEleman = temp;
	}
}

void ekranaYazdir(){
	system("cls");
	if(ilkEleman == NULL){
		printf("\nKuyruk bos!\n");
	}
	else{
		temp = ilkEleman;
		while(temp->sonraki != NULL){
			printf("%d ", temp->veri);
			temp = temp->sonraki;
		}
		printf("%d ", temp->veri);
	}
}

int main(){
	int sayi, secim;
	while(1){
		printf("\n--------STATIC QUEUE-------\n");
		printf("Eleman Eklemek Icin -----> 1\n");
		printf("Eleman Cikarmak Icin  ---> 2\n");
		printf("Ekrana Yazdirmak Icin----> 3\n");
		printf("Cikis Icin -------- -----> 4\n");
		printf("Seciminizi Yapiniz: ");	scanf("%d", &secim);
		
		switch(secim){
			case 1:	printf("\nEklenecek Sayi: ");	scanf("%d", &sayi);
					elemanEkle(sayi);
					break;
			case 2:	elemanSil();
					break;
			case 3: ekranaYazdir();
					break;
			case 4:	exit(1);
					break;
		}
	}
}
