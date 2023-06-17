#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *next;
};

struct dugum *ilkEleman = NULL;
struct dugum *temp = NULL;

void basaEkle(int sayi){
	struct dugum * eklenecekVeri;
	eklenecekVeri = (struct dugum *) malloc(sizeof (struct dugum));
	eklenecekVeri->veri = sayi;
	eklenecekVeri->next = ilkEleman; // !!!!!!!!!!
	ilkEleman = eklenecekVeri;		 // !!!!!!!!!!
}

void ekranaYazdir(){
	temp = ilkEleman;
	printf("\n");
	// Veriler ekrana yazdýrýlýr.
	while(temp->next !=NULL){
		printf("Girilen Sayi: %d\n", temp->veri);
		temp = temp->next;
	}
	// Yukarýda NULL'ý buldugu zaman donguden ciktigi icin son veri burada yazdýrýlýr.
	printf("Girilen Ilk Sayi: %d", temp->veri);
}

int main(){
	int adet = 0;
	int sayi;
	// 5 adet veri aliyoruz.
	while(adet !=6){
		printf("Sayi giriniz: ");	scanf("%d", &sayi);	
		basaEkle(sayi);
		adet = adet+1;
	}
	ekranaYazdir();
	return 0;
}
