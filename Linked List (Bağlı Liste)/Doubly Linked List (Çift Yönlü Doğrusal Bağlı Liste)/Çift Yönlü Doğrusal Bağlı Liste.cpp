#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *onceki;
	struct dugum *sonraki;
};

struct dugum* ilkEleman = NULL;
struct dugum *sonraki   = NULL;
struct dugum *onceki    = NULL;
struct dugum *temp      = NULL;
struct dugum *temp2     = NULL;

void basaEkle(int kullanicininGirdigiSayi){
	struct dugum *eleman = (struct dugum *) malloc(sizeof (struct dugum));
	eleman->onceki = NULL;
	eleman->veri   = kullanicininGirdigiSayi;
	
	if(ilkEleman == NULL){
		ilkEleman = eleman;
		ilkEleman->sonraki = NULL;
	}
	else{
		eleman->sonraki = ilkEleman;
		ilkEleman = eleman;
	}
}

void sonaEkle(int kullanicininGirdigiSayi){
	struct dugum *eleman = (struct dugum *) malloc(sizeof (struct dugum));
	eleman->veri    = kullanicininGirdigiSayi;
	eleman->sonraki = NULL;
	
	if(ilkEleman == NULL){
		ilkEleman = eleman;
		ilkEleman->sonraki = NULL;
		ilkEleman->onceki = NULL;
	}
	else{
		if(ilkEleman->sonraki == NULL){
			ilkEleman->sonraki = eleman;
			eleman->onceki = ilkEleman;
		}
		else{
			temp = ilkEleman;
			// while ile son dugum bulunur.
			while(temp->sonraki != NULL){
				temp = temp->sonraki;
			}
			temp->sonraki = eleman;
			eleman->onceki = temp;
		}
	}
}

void bastanSil(){	
	if(ilkEleman == NULL){
		printf("\nListe bos!\n");
	}
	else{
		// Sadece tek bir eleman yani tek bir dugum varsa asagidaki if blogu calisir.
		if(ilkEleman->sonraki == NULL){
			free(ilkEleman);
			ilkEleman = NULL;
		}
		// Listede birden fazla eleman yani dugum varsa else bloguna girer.
		else{
			temp = ilkEleman->sonraki;
			free(ilkEleman);
			temp->onceki = NULL;
			ilkEleman = temp;
		}
	}
}
            
void sondanSil(){
	if(ilkEleman == NULL){
		printf("\nListe bos!\n");
	}
	else{
		// Sadece tek bir eleman yani tek bir dugum varsa asagidaki if blogu calisir.
		if(ilkEleman->sonraki == NULL){
			free(ilkEleman);
			ilkEleman = NULL;
		}
		// Listede birden fazla eleman yani dugum varsa else bloguna girer.
		else{
			temp = ilkEleman;
			// Son dugumden bir onceki dugum sonraki'ye atanmis oluyor.
			while(temp->sonraki->sonraki != NULL){
				temp = temp->sonraki;
			}
			temp2 = temp;
			free(temp->sonraki);
			temp2->sonraki = NULL;
		}
	}
}

int elemanSayisi(){
	system("cls"); 
	int adet = 0;
	
	if(ilkEleman == NULL)	{
		return 0;
	}
	else{
		temp = ilkEleman;
		while(temp->sonraki != NULL){
			adet++;
			temp = temp->sonraki;
		}
		adet++;
	}
	return adet;
}

int elemanToplami(){
	system("cls"); 
	int toplam = 0;
	
	if(ilkEleman == NULL)	{
		return 0;
	}
	else{
		temp = ilkEleman;
		while(temp->sonraki != NULL){
			toplam = toplam + temp->veri;
			temp = temp->sonraki;
		}
		toplam = toplam + temp->veri;
	}
	return toplam;
}

void listele(){
	system("cls");
	if(ilkEleman == NULL){
		printf("Liste Bos!");
	}
	else{
		temp = ilkEleman;
		// Son dugumu yani elemani bulana kadar while dongusu calisir.
		while(temp->sonraki != NULL){
			printf("%d -> ", temp->veri);
			temp = temp->sonraki;
		}
		printf("%d", temp->veri);
	}
}

int main(){
	while(1){
	int secim, sayi;
	printf("\n----------MENU----------");
	printf("\nBasa eklemek icin ------------> 1\n");
	printf("Sona eklemek icin ------------> 2\n");
	printf("Bastan eleman silmek icin ----> 3\n");
	printf("Sondan eleman silmek icin ----> 4\n");
	printf("Listedeki eleman sayisi icin -> 5\n");
	printf("Elemanlarin toplami icin -----> 6\n");
	printf("Listelemek icin --------------> 7\n");
	printf("Cikis yapmak icin ------------> 8\n");
	printf("Seciminizi yapiniz: ");	scanf("%d", &secim);
	
		switch(secim){
			case 1:	printf("\nBasa Eklenecek Sayiyi Giriniz: ");	scanf("%d", &sayi);
					basaEkle(sayi);
					break;
			case 2:	printf("\nSona Eklenecek Sayiyi Giriniz: ");	scanf("%d", &sayi);
					sonaEkle(sayi); 
					break;
			case 3:	bastanSil();
					break;
			case 4:	sondanSil();
					break;
			case 5:	printf("Eleman Sayisi: %d\n ", elemanSayisi());
					break;
			case 6: printf("Elemanlarin Toplami: %d\n ", elemanToplami());
					break;
			case 7: listele();
					break;
			case 8:	exit(1);
		}
	}
}
