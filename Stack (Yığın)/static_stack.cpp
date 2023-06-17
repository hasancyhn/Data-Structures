// STATIC STACK

#include <stdio.h>
#include <stdlib.h>
#define uzunluk 10	// UZUNLUK isimli deðiþkene 10 deðerini atadýk.

struct stack{
	int dizi[uzunluk];
	int indis;	// top
};

struct stack nesne1;

// PUSH Metodu
void elemanEkle(int kullanicininGirdigiSayi){
	if(nesne1.indis == uzunluk-1){	// indis 10-1'den 9'a kadar gider.
		printf("Yigin dolu!");
	}
	else{
		nesne1.indis++;
		nesne1.dizi[nesne1.indis] = kullanicininGirdigiSayi;
	}
}

// POP Metodu
void elemanCikar(int kullanicininGirdigiSayi){
	if(nesne1.indis == -1){	// indis 10-1'den 9'a kadar gider.
		printf("\nYigin bos, cikacak eleman yoktur!\n");
	}
	else{
		int cikanSayi = nesne1.dizi[nesne1.indis];
		nesne1.indis --;
		printf("\n%d Sayisi Yigindan Cikarildi.\n", cikanSayi);
	}
}

void ekranaYazdir(){
	system("cls");
	if(nesne1.indis == -1){
		printf("Yigin Bos!\n");
	}
	else{
		int i;
		for(i=nesne1.indis; i>-1; i--){
			printf("%d\n", nesne1.dizi[i]);
		}
	}
}

int main(){
	nesne1.indis = -1;	// Yýðýnýn içinin boþ olduðu anlamý çýkarýlýr.
	int secim, sayi;
	
	while(1){
		printf("\n----------STATIC STACK----------\n");
		printf("Eleman Eklemek Icin  (PUSH) ---> 1\n");
		printf("Eleman Cikarmak Icin (POP)  ---> 2\n");
		printf("Ekrana Yazdirmak Icin ---------> 3\n");
		printf("Cikis Icin --------------------> 4\n");
		printf("Seciminizi Yapiniz: ");	scanf("%d", &secim);
		
		switch(secim){
			case 1:	printf("\nEklenecek Sayi: ");	scanf("%d", &sayi);
					elemanEkle(sayi);
					break;
			case 2:	elemanCikar(sayi);
					break;
			case 3: ekranaYazdir();
					break;
			case 4:	exit(1);
					break;
		}
	}
}

