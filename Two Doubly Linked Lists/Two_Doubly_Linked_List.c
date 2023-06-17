// HASAN CEYHAN 20010011091 --> Veri Yapýlarý Ödev2 --> Hafta4 Çift Yönlü Baðlý Liste
// Neden 2 farklý liste oluþturduk hafýzada sýralý bir þekilde oluþmasý için slaytta
// 5. sayfaya bakacak olursan anlatsýn (root1=1 root2=2 root1'in yanýndaki 3 root2'nin yanýndaki 4 ...)
#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int x;
    struct dugum * sonraki;
    struct dugum * onceki;
};

// Baðlý liste sayýsý
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
    // Kullanýcýdan liste uzunluðunun alýndýðý blok
    //-----------------------------------------------------------------------------

    printf("\nListe icin bir sayi giriniz: "); 		scanf("%d", &dugum_Sayisi);
    printf("\n\n");

    //-----------------------------------------------------------------------------
    // 2 farklý listenin oluþturulduðu blok
    //-----------------------------------------------------------------------------

    // srand() KULLANIMI HAKKINDA BÝLGÝ
	// Eðer srand() fonksiyonunu kullanmazsak program rand()’ýn seed deðerini srand(1) olarak ayarlar ve bu da her seferinde ayný sayý dizisini karþýmýza çýkarýr.
	// srand() fonksiyonu bilgisayarýn saatini kullananýr.
	// Özetle rand() fonksiyonu her seferinde ayný seriyi üretmemesi için kullandýk.
    srand(time(NULL));

    // Ýlk olarak ilk listenin root1'ini (ilk eleman) oluþturduk.
    struct dugum * root1 =(struct dugum*) malloc(sizeof(struct dugum));
    root1->x = rand()%  100;
    root1->sonraki = NULL;
    root1->onceki = NULL;

    // Sonra ikinci listenin root2'sini (ilk eleman) oluþturudk.
    struct dugum * root2 =(struct dugum*) malloc(sizeof(struct dugum));
    root2->x = rand()%  100;
    root2->sonraki = NULL;
    root2->onceki = NULL;

    int i;
    struct dugum *gezici;

    for (i=0; i<dugum_Sayisi-1;i++){
        // 1. liste için
        struct dugum *ilkKayit = (struct dugum*) malloc(sizeof(struct dugum));
        ilkKayit->x = rand()%  100;
		// gezici'yi sürekli root1'e eþitleriz çünkü listede tek bildiðimiz, elimizde tuttuðumuz deðer root1'dir.
        gezici = root1;

        while (gezici->sonraki != NULL)
            gezici = gezici->sonraki;

        gezici->sonraki = ilkKayit;
        ilkKayit->onceki = gezici;
        ilkKayit->sonraki = NULL;

        // 2. liste için
        // root1 için yapýlan iþlemlerin aynýsý root2 içinde geçerli.
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
    // Birleþtirme iþleminin yapýldýðý kod bloðu
    //-----------------------------------------------------------------------------

    gezici = root1;
    struct dugum* tasinacakDugum;

    for (i=0; i<dugum_Sayisi; i++){
        tasinacakDugum = root2;

        // 2. listenin son elamaný farklý iþlem görecek, onun kontrolu yapýlýyor.
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
    // Ters çevirme iþleminin yapýldýðý kod bloðu
    //-----------------------------------------------------------------------------

    struct dugum* temp = (struct dugum*) malloc(sizeof(struct dugum));	// temp'i oluþturmamýzýn sebebi verileri aktarýrken kaybetmemek için.

    // Ýki liste birleþtiði için artik dugum_Sayisi'nýn iki katý kadar eleman var.
    for (i=0; i<dugum_Sayisi*2;i++){
    	// gezici'yi sürekli root1'e eþitleriz çünkü listede tek bildiðimiz, elimizde tuttuðumuz deðer root1'dir.
        gezici = root1;
        temp->sonraki = gezici->sonraki;
        temp->onceki = gezici->onceki;

        // Son elemana geldiðinde artýk root burasadýr bir sonraki elemana atama yapýlmaz.
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
