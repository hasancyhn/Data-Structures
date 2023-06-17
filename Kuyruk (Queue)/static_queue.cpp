// STATIC QUEUE

#include <stdio.h>
#include <stdlib.h>
#define uzunluk 5

int dizi[uzunluk];
int ilkEleman = -1,    sonEleman = -1;
 // ilkEleman = FRONT  sonEleman = REAR


void elemanEkle(int kullanicininGirdigiVeri){
	if(sonEleman == uzunluk-1){
		printf("\nKuyruk dolu!\n");
	}
	else{
		if(ilkEleman == -1){
			ilkEleman = 0;
		}
		sonEleman++;
		dizi[sonEleman] = kullanicininGirdigiVeri;
	}
}

void elemanSil(){
	if(ilkEleman == -1 || ilkEleman>sonEleman){
		printf("\nKuyruk bostur!\n");
		ilkEleman = -1;
		sonEleman = -1;
	}
	else{
		ilkEleman = ilkEleman + 1;
	}
}

void ekranaYazdir(){
	system("cls");
	if(ilkEleman == -1){
		printf("\nKuyruk bos!\n");
	}
	else{
		int i;
		for(i=ilkEleman; i<=sonEleman; i++){
			printf("%d ", dizi[i]);
		}
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
