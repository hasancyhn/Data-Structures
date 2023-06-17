#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum * next;
};

struct dugum *ilkEleman = NULL;
struct dugum *temp = NULL;

void basaEkle(int data){
	struct dugum * eklenecekVeri;
	eklenecekVeri = (struct dugum *) malloc(sizeof (struct dugum));
	eklenecekVeri->veri = data;
	eklenecekVeri->next = ilkEleman; // !!!!!!!!!!
	ilkEleman = eklenecekVeri;		 // !!!!!!!!!!
}

// arayaEklenecekSayi araya eklemek istedigimiz sayiyi temsil ediyor.
// x, aradigimiz sayi bulununca onune dugum eklemek icin kullandiðimiz degerdir.
void arayaEkle(int x, int arayaEklenecekSayi){
	struct dugum * eklenecekVeri;
	eklenecekVeri = (struct dugum *) malloc(sizeof (struct dugum));
	eklenecekVeri->veri = arayaEklenecekSayi;
	
	temp = ilkEleman;
	while(temp->next->veri != x){
		temp = temp->next;
	}
	// Araya dugum eklemek icin gecici bir dugum olusturduk.	
	struct dugum * temp2;
	temp2 = (struct dugum *) malloc(sizeof (struct dugum));
	
	temp2 = temp->next;
	temp->next = eklenecekVeri;
	eklenecekVeri->next = temp2;
}

void sonaEkle(int data){
	struct dugum * eklenecekVeri;
	eklenecekVeri = (struct dugum *) malloc(sizeof (struct dugum));
	eklenecekVeri->veri = data;
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
	if(ilkEleman != NULL){
		temp = ilkEleman;
		printf("\n");
		// Veriler ekrana yazdýrýlýr.
		while(temp->next !=NULL){
			printf("Girilen Sayi: %d\n", temp->veri);
			temp = temp->next;
		}
		// Yukarýda NULL'ý buldugu zaman donguden ciktigi icin son veri burada yazdýrýlýr.
		printf("Girilen Sayi: %d\n", temp->veri);
		printf("\n");
	}
	else{
		printf("Eleman yok!\n");
	}
}

void bastanSil(){
	if(ilkEleman != NULL){
	temp = ilkEleman->next; // Ilk elemanin next'ini temp degiskenine attik.
	free(ilkEleman);		// Ilk eleman silindi boylelikle temp'in icinde tutulan eleman ilkEleman olmus oldu.
	ilkEleman = temp; 
	}
	else{
		free(ilkEleman);
	}
}

void sondanSil(){
	if(ilkEleman != NULL){
		temp = ilkEleman;
		// Ne kadar next varsa  o kadar dugum ilerleriz.
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		// Son dugum silindi.
		free(temp->next);
		temp->next = NULL;
	}
	else{
		bastanSil();
	}
}

void aradanSil(int data){
	temp = ilkEleman;
	if(temp->veri == data){
		bastanSil();
	}
	else{
		struct dugum * temp2;
		temp2 = (struct dugum*) malloc (sizeof(struct dugum));
		
		while(temp->next->veri != data){
			temp = temp->next;
		}
		if(temp->next->next == NULL){
			sondanSil();
		}
		else{
			temp2 = temp->next->next;
			free(temp->next);
			temp->next = temp2;
		}
	}
}

void tersCevir(){
	
	struct dugum * temp2   = NULL;
	struct dugum * onceki  = NULL;

	temp = ilkEleman;
	while(temp != NULL){
		temp2 = temp->next;
		temp->next = onceki;
		onceki = temp;
		temp = temp2;
	}
	ilkEleman = onceki;
}

int dugumSayisi(){
	int adet = 0;
	if(ilkEleman == NULL){
		return adet;
	}
	else{
		temp = ilkEleman;
		while(temp->next != NULL){
			adet++;
			temp = temp->next;
		}
		adet++;
		return adet;
	}
}

int verilerinToplami(){
	int toplam = 0;
	if(ilkEleman == NULL){
		return 0;
	}
	else{
		temp = ilkEleman;
		while(temp->next != NULL){
			toplam+= temp->veri;
			temp = temp->next;
		}
		toplam += temp->veri;
	}
	return toplam;
}
int main (){
	int adet = 0, sayi, secim, hangiSayidanOnce;
	while(true){
		printf("-------------MENU-------------\n");
		printf("Basa   eleman eklemek icin  1\n");
		printf("Sona   eleman eklemek icin  2\n");
		printf("Araya  eleman eklemek icin  3\n");
		printf("Bastan eleman silmek  icin  4\n");
		printf("Sondan eleman silmek  icin  5\n");
		printf("Aradan eleman silmek  icin  6\n");
		printf("Ters   cevirmek       icin  7\n");
		printf("Toplam dugum sayisi   icin  8\n");
		printf("Verilerin toplamini   icin  9\n");
		printf("Cikis   yapmak        icin  0\n");
		printf("Seciminizi yapin: ");	scanf("%d", &secim);
		printf("\n");
		
		switch(secim){
			case 1: printf("Basa Eklenecek Sayi: ");			scanf("%d", &sayi);	
					basaEkle(sayi);
					ekranaYazdir();
					break;
			case 2: printf("Sona Eklenecek Sayi: : ");			scanf("%d", &sayi);	
					sonaEkle(sayi);
					ekranaYazdir();
					break;
			case 3: printf("Hangi sayidan once eklenilsiz: "); 	scanf("%d", &hangiSayidanOnce);
					printf("Araya Eklenecek Sayi: ");			scanf("%d", &sayi);	
					arayaEkle(hangiSayidanOnce ,sayi);
					ekranaYazdir();
					break;
			case 4: bastanSil();
					ekranaYazdir();
					break;
			case 5: sondanSil();
					ekranaYazdir();
					break;
			case 6: printf("Aradan hangi sayi silinsin: ");		scanf("%d", &sayi);
					aradanSil(sayi);
					ekranaYazdir();
					break;
			case 7: tersCevir();
					ekranaYazdir();
					break;
			case 8: printf("Dugum sayisi: %d\n", dugumSayisi());
					ekranaYazdir();
					break;
			case 9: printf("Verilerin toplami: %d\n", verilerinToplami());
					break;
			case 0: exit(0);
					break;
		}
		adet++;
	}
	return 0;
}
