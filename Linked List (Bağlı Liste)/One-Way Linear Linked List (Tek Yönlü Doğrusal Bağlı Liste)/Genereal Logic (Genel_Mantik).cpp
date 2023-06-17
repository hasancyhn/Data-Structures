#include <stdio.h>
#include <stdlib.h>
#include <cstring>
// Tek yonlu bagli listenin son gostericisi yani pointer'i NULL'dýr.
struct ogrenci{		// Dugum olusturma kalibi.
	char isim[10];
	char soyisim[10];
	char cinsiyet[2];
	int yas;
	struct ogrenci *next;
};

int main (){
	struct ogrenci * ogr1;	// Ilk dugumu olusturduk
	ogr1 = (struct ogrenci *) malloc (sizeof (struct ogrenci));	// Bellekte yer ayirdik.
	
	struct ogrenci * ogr2;
	ogr2 = (struct ogrenci *) malloc (sizeof (struct ogrenci));
	
	struct ogrenci * ogr3;
	ogr3 = (struct ogrenci *) malloc (sizeof (struct ogrenci));
	
	strcpy(ogr1->isim, "Hasan");
	strcpy(ogr1->soyisim, "CEYHAN");
	strcpy(ogr1->cinsiyet, "E");
	printf("Yas giriniz:");			scanf("%d", &ogr1->yas);
	ogr1->next = ogr2;

	strcpy(ogr2->isim, "Beyza");
	strcpy(ogr2->soyisim, "ATA");
	strcpy(ogr2->cinsiyet, "K");
	printf("Yas giriniz:");			scanf("%d", &ogr2->yas);
	ogr2->next = ogr3;

	strcpy(ogr3->isim, "Fatih");
	strcpy(ogr3->soyisim, "ESKICI");
	strcpy(ogr3->cinsiyet, "E");
	printf("Yas giriniz:");			scanf("%d", &ogr3->yas);
	ogr3->next = NULL;

	printf("\n%s %s %s %d\n", ogr1->isim, ogr1->soyisim, ogr1->cinsiyet, ogr1->yas);
	printf("%s %s %s %d\n", ogr2->isim, ogr2->soyisim, ogr2->cinsiyet, ogr2->yas);
	printf("%s %s %s %d", ogr3->isim, ogr3->soyisim, ogr3->cinsiyet, ogr3->yas);
	return 0;
}
