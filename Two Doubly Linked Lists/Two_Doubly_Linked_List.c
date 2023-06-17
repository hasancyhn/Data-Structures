// HASAN CEYHAN 20010011091 --> Veri Yap�lar� �dev2 --> Hafta4 �ift Y�nl� Ba�l� Liste
// Neden 2 farkl� liste olu�turduk haf�zada s�ral� bir �ekilde olu�mas� i�in slaytta
// 5. sayfaya bakacak olursan anlats�n (root1=1 root2=2 root1'in yan�ndaki 3 root2'nin yan�ndaki 4 ...)
#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int x;
    struct dugum * sonraki;
    struct dugum * onceki;
};

// Ba�l� liste say�s�
int dugum_Sayisi;

void ekrana_yaz(struct dugum *root){
    struct dugum *gezici = root;

    while (gezici != NULL){
        printf("\n%d degerinin yer aldigi hafiza numarasi %d", gezici->x, gezici);
        gezici = gezici->sonraki;
    }
}

int main (){
    //-----------------------------------------------------------------------------
    // Kullan�c�dan liste uzunlu�unun al�nd��� blok
    //-----------------------------------------------------------------------------

    printf("\nListe icin bir sayi giriniz: "); 		scanf("%d", &dugum_Sayisi);
    printf("\n\n");

    //-----------------------------------------------------------------------------
    // 2 farkl� listenin olu�turuldu�u blok
    //-----------------------------------------------------------------------------

    // srand() KULLANIMI HAKKINDA B�LG�
	// E�er srand() fonksiyonunu kullanmazsak program rand()��n seed de�erini srand(1) olarak ayarlar ve bu da her seferinde ayn� say� dizisini kar��m�za ��kar�r.
	// srand() fonksiyonu bilgisayar�n saatini kullanan�r.
	// �zetle rand() fonksiyonu her seferinde ayn� seriyi �retmemesi i�in kulland�k.
    srand(time(NULL));

    // �lk olarak ilk listenin root1'ini (ilk eleman) olu�turduk.
    struct dugum * root1 =(struct dugum*) malloc(sizeof(struct dugum));
    root1->x = rand()%  100;
    root1->sonraki = NULL;
    root1->onceki = NULL;

    // Sonra ikinci listenin root2'sini (ilk eleman) olu�turudk.
    struct dugum * root2 =(struct dugum*) malloc(sizeof(struct dugum));
    root2->x = rand()%  100;
    root2->sonraki = NULL;
    root2->onceki = NULL;

    int i;
    struct dugum *gezici;

    for (i=0; i<dugum_Sayisi-1;i++){
        // 1. liste i�in
        struct dugum *ilkKayit = (struct dugum*) malloc(sizeof(struct dugum));
        ilkKayit->x = rand()%  100;
		// gezici'yi s�rekli root1'e e�itleriz ��nk� listede tek bildi�imiz, elimizde tuttu�umuz de�er root1'dir.
        gezici = root1;

        while (gezici->sonraki != NULL)
            gezici = gezici->sonraki;

        gezici->sonraki = ilkKayit;
        ilkKayit->onceki = gezici;
        ilkKayit->sonraki = NULL;

        // 2. liste i�in
        // root1 i�in yap�lan i�lemlerin ayn�s� root2 i�inde ge�erli.
        struct dugum *ikinciKayit = (struct dugum*) malloc(sizeof(struct dugum));
        ikinciKayit->x = rand()%  100;

        struct dugum *gezici2 = root2;

        while (gezici2->sonraki != NULL)
            gezici2 = gezici2->sonraki;

        gezici2->sonraki = ikinciKayit;
        ikinciKayit->onceki = gezici2;
        ikinciKayit->sonraki = NULL;
    }
    printf("-----------------------------------------------");
    printf("\nIlk olusturulan cift yonlu bagli liste\n");
    printf("-----------------------------------------------");
    ekrana_yaz(root1);
    printf("\n\n-----------------------------------------------");
    printf("\nIkinci olusturulan cift yonlu bagli liste\n");
    printf("-----------------------------------------------");
    ekrana_yaz(root2);

    //-----------------------------------------------------------------------------
    // Birle�tirme i�leminin yap�ld��� kod blo�u
    //-----------------------------------------------------------------------------

    gezici = root1;
    struct dugum* tasinacakDugum;

    for (i=0; i<dugum_Sayisi; i++){
        tasinacakDugum = root2;

        // 2. listenin son elaman� farkl� i�lem g�recek, onun kontrolu yap�l�yor.
        if(tasinacakDugum->sonraki == NULL){
            gezici->sonraki = tasinacakDugum;
            tasinacakDugum->onceki = gezici;
        }
        else{
            tasinacakDugum->sonraki->onceki = NULL;
            root2 = tasinacakDugum->sonraki;
            tasinacakDugum->sonraki = gezici->sonraki;
            gezici->sonraki->onceki = tasinacakDugum;
            gezici->sonraki = tasinacakDugum;
            tasinacakDugum->onceki = gezici;
       }
        gezici = gezici->sonraki->sonraki;
    }
	printf("\n\n-----------------------------------------------");
    printf("\nBirlestirilmis Liste\n");
    printf("-----------------------------------------------");
    ekrana_yaz(root1);

    //-----------------------------------------------------------------------------
    // Ters �evirme i�leminin yap�ld��� kod blo�u
    //-----------------------------------------------------------------------------

    struct dugum* temp = (struct dugum*) malloc(sizeof(struct dugum));	// temp'i olu�turmam�z�n sebebi verileri aktar�rken kaybetmemek i�in.

    // �ki liste birle�ti�i i�in artik dugum_Sayisi'n�n iki kat� kadar eleman var.
    for (i=0; i<dugum_Sayisi*2;i++){
    	// gezici'yi s�rekli root1'e e�itleriz ��nk� listede tek bildi�imiz, elimizde tuttu�umuz de�er root1'dir.
        gezici = root1;
        temp->sonraki = gezici->sonraki;
        temp->onceki = gezici->onceki;

        // Son elemana geldi�inde art�k root burasad�r bir sonraki elemana atama yap�lmaz.
        if(gezici->sonraki != NULL){
            root1 = gezici->sonraki;
        }
        gezici->sonraki = temp->onceki;
        gezici->onceki = temp->sonraki;
    }
	printf("\n\n-----------------------------------------------");
    printf("\nTers Cevrilmis Liste\n");
    printf("-----------------------------------------------");
    ekrana_yaz(root1);
    return 0;
}
