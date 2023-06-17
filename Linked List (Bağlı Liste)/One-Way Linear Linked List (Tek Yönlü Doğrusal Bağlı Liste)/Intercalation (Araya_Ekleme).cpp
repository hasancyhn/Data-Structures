#include <stdio.h>
#include <stlib.h>

struct dugum{
	int veri;
	struct dugum *next;
};

struct dugum *ilkEleman = NULL;
struct dugum *temp = NULL;


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


int main() {
	
}
