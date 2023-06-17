#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum * next;
};

struct dugum *ilkEleman = NULL;
struct dugum *temp = NULL;

void sonaEkle(int sayi){
	struct dugum * eklenecekVeri;
	eklenecekVeri = (struct dugum *) malloc(sizeof (struct dugum));
	eklenecekVeri->veri = sayi;
	eklenecekVeri->next = NULL;	// !!!!!!!!!!
	
	// Dugumde hic veri yoksa bu if bloguna girer.
	if(ilkEleman == NULL){	
		ilkEleman = eklenecekVeri;
	}
	// Ilk dugum doluysa (veri varsa) son dugumu bulmak icin while dongusu kullanýlýr.
	else{
		temp = ilkEleman;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = eklenecekVeri;
	}
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
	printf("Girilen Son Sayi: %d", temp->veri);
}

int main(){
	int adet = 0;
	int sayi;
	// 5 adet veri aliyoruz.
	while(adet !=5){
		printf("Sayi giriniz: ");	scanf("%d", &sayi);	
		sonaEkle(sayi);
		adet = adet+1;
	}
	ekranaYazdir();
	return 0;
}
