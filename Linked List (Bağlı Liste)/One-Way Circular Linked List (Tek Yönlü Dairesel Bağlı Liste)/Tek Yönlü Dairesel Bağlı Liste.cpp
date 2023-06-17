#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};

struct dugum * ilkEleman = NULL;
struct dugum * temp      = NULL;
struct dugum * onceki    = NULL;
struct dugum * last      = NULL;

void basaEkle(int kullanicininGirdigiSayi){
	 struct dugum *eleman = (struct dugum *) malloc(sizeof(struct dugum));
	 eleman->veri = kullanicininGirdigiSayi;
	
	 // Ilk dugum bos ise if bloguna girerek ilk dugum olusturulur.
	 if(ilkEleman == NULL){
	 	ilkEleman = eleman;
	 	eleman->sonraki = ilkEleman;
	 }
	 else{
	 	temp = ilkEleman;
	 	// Son dugum bulunana kadar while döngüsü çalýþýr.
	 	while(temp->sonraki != ilkEleman){
	 		temp = temp->sonraki;
		 }
		 temp->sonraki = eleman;
		 eleman->sonraki = ilkEleman;
		 ilkEleman = eleman;
	 }
}
// basaEkle() ile sonaEkle()'nin farký else kýsmýnda bir satýrlýk kodu sildik.
void sonaEkle(int kullanicininGirdigiSayi){
	 struct dugum *eleman = (struct dugum *) malloc(sizeof(struct dugum));
	 eleman->veri = kullanicininGirdigiSayi;
	 
	 // Ilk dugum bos ise if bloguna girerek ilk dugum olusturulur.
	 if(ilkEleman == NULL){
	 	ilkEleman = eleman;
	 	eleman->sonraki = ilkEleman;
	 }
	 else{
	 	temp = ilkEleman;
	 	// Son dugum bulunana kadar while döngüsü çalýþýr.
	 	while(temp->sonraki != ilkEleman){
	 		temp = temp->sonraki;
		 }
		 temp->sonraki = eleman;
		 eleman->sonraki = ilkEleman;	// eleman->sonraki, son dugumu gsoteriyor.
	 }
}

void bastanSil(){	
	if(ilkEleman == NULL){
		printf("\nListe bos!\n");
	}
	else{
		// Sadece tek bir eleman yani tek bir dugum varsa asagidaki if blogu calisir.
		// Tek yonlu dairesel bagli listede bir eleman varsa kendisini gosterir.
		if(ilkEleman->sonraki == ilkEleman){
			free(ilkEleman);
			ilkEleman = NULL;
		}
		// Listede birden fazla eleman yani dugum varsa else bloguna girer.
		else{
			last = ilkEleman;
			while(last->sonraki != ilkEleman){
				last = last->sonraki;
			}
			temp = ilkEleman->sonraki;
			free(ilkEleman);
			last->sonraki = temp;	// temp'in icinde ilkEleman'dan sonraki dugum vardi.
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
		// Dairesel bagli listede bir eleman varsa kendisini gosterir.
		if(ilkEleman->sonraki == ilkEleman){
			free(ilkEleman);
			ilkEleman = NULL;
		}
		// Listede birden fazla eleman yani dugum varsa else bloguna girer.
		else{
			last = ilkEleman;
			// ilkEleman'i gosteren dugumden onceki dugume kadar gidiyor.
			while(last->sonraki->sonraki != ilkEleman){
				last = last->sonraki;
			}
			temp = last;				// temp'e en son dugumden bir onceki dugumu atadik.
			free(last->sonraki);	
			last->sonraki = ilkEleman;	// temp'in icinde ilkEleman'dan sonraki dugum vardi.ümüne baðlýyoruz 
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
		while(temp->sonraki != ilkEleman){
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
		while(temp->sonraki != ilkEleman){
			toplam = toplam + temp->veri;
			temp = temp->sonraki;
		}
		toplam = toplam+ temp->veri;
	}
	return toplam;
}

void listele(){
	system("cls"); 
	if(ilkEleman == NULL){
		printf("Liste bos!\n\n");
	}
	else{
		temp = ilkEleman;
		while(temp->sonraki != ilkEleman){
			printf("%d -> ", temp->veri);
			temp = temp->sonraki;
		}
		printf("%d\n\n", temp->veri);
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
