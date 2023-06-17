// HASAN CEYHAN 20010011091
/* Prim ve Kruskal Algoritmalari kullanicidan alinan degerler
   dogrultusunda (dosyadaki ekran goruntulerinde mevcut) en kisa yolu hesaplayacaktir.	
*/
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <algorithm>
#include <vector>

#define infinity 9999
#define MAX 20

using namespace std;

// KRUSKAL ALGORITMASI
class kenar{
    public:
    int s;
    int d;
    int w;
    kenar(){
    }

    kenar(int kaynak, int mesafee, int agirlikk){
        s = kaynak;
        d = mesafee;
        w = agirlikk;
    }
};

bool kenarlariKarsilastir(kenar e1, kenar e2){
    return e1.w<e2.w;
}

int atayiBul(int i, int* ata ){
    if(ata[i]==i)
        return i;
    return atayiBul(ata[i],ata);
}

class graph{
    public:
    int e, n;
    kenar* v;

    graph(int n, int e){
        this->n = n;
        this->e = e;
        v = new kenar[e];
        for(int i=0; i<e; i++){
            int x, y, w;
            cout<<"Koseleri ve Kenar Agirliklarini Giriniz "<<i+1<<" :	";
            cin>>x>>y>>w;
            kenar e(x, y, w);
            v[i] = e;
        }
    }

    kenar* unionfind(){
        int* ata = new int[n];
        for(int i=0; i<n; i++){
            ata[i] = i;
        }

        sort(v, v+e, kenarlariKarsilastir);
        kenar* ciktimiz;
        ciktimiz = new kenar[n-1];
        int sayac = 0, i = 0;
        while(sayac != n-1){
            kenar c = v[i];
            int kaynakAta = atayiBul(v[i].s, ata);
            int desparent = atayiBul(v[i].d, ata);
            if(kaynakAta != desparent){
                ciktimiz[sayac] = c;
                ata[kaynakAta] = desparent;
                sayac++;
            }
            i++;
        }
        int sum=0;
        cout<<endl<<"-------MST-------\n";
        
       for(int i=0; i<n-1; i++){
           cout<<ciktimiz[i].s<<"	"<<ciktimiz[i].d<<"	"<<ciktimiz[i].w<<endl;
           sum += ciktimiz[i].w;
       }
       cout<<"\nMST'nin Agirligi: "<<sum;
       cout<<"\n\n";
    }
};

// PRIM ALGORITMASI
int G[MAX][MAX], spanning[MAX][MAX], n;
int prims();

int main() {
	while(1){
		int secim;
		cout<<"\n****************MENU***************"<<endl;
		cout<<"Prim Algoritmasi ---------------> 1"<<endl;
		cout<<"Kruskal Algoritmasi ------------> 2"<<endl;
		cout<<"Cikis Icin ---------------------> 0\n"<<endl;
		cout<<"Seciminizi Yapin: ";	cin>>secim;
		switch(secim){
			case 1: 
			{
				int i, j, toplamMaliyet;
				printf("Kose Sayisini Giriniz: ");	scanf("%d",&n);
				printf("\nAdjacency Matrix Degerlerini Giriniz:\n");
				for(i=0; i<n; i++)
					for(j=0; j<n; j++)
						scanf("%d", &G[i][j]);
						toplamMaliyet = prims();
						printf("\nSpanning Tree Matrix:\n");
					for(i=0; i<n; i++){
						printf("\n");
					for(j=0; j<n; j++)
						printf("%d\t",spanning[i][j]);
					}				
				printf("\n\nToplam Maliyet = %d", toplamMaliyet);
				printf("\n\n");
				break;
			}		
			case 2:
			{
				int n,e;
    			cout<<"Kose Sayisini Giriniz:	";	cin>>n;
    			cout<<"Kenar Sayisini Giriniz:	";	cin>>e;
    			graph g(n,e);
    			kenar* mst=g.unionfind();
    			break;
			}
			case 0:
				{
				cout<<"\nCikis Saglandi!"<<endl;
					return 0;
				}
		}	
	}
	return 0;
}

// PRIM ALGORITMASI
int prims(){
	int maliyet[MAX][MAX];
	int u, v, minMesafe, mesafe[MAX], baslangicNoktasi[MAX];
	int ziyaretEdilen[MAX], kenarNumarasi, i, minMaliyet,j;
	
	// Maliyet matrix'i [][] ve spanning[][] olusturma.
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(G[i][j]==0)
			maliyet[i][j]=infinity;
			else
				maliyet[i][j]=G[i][j];
				spanning[i][j]=0;
		}
		
	// ziyaretEdilen[][], mesafe[][] ve baslangicNoktasi[][]
	mesafe[0]=0;
	ziyaretEdilen[0]=1;
	for(i=1;i<n;i++){
		mesafe[i]=maliyet[0][i];
		baslangicNoktasi[i]=0;
		ziyaretEdilen[i]=0;
	}
	
	minMaliyet=0; // Yayilan agacin maliyeti
	kenarNumarasi=n-1; // Eklenecek kenar sayisi
	while(kenarNumarasi>0){
		// Minimum mesafyi buluruz
		minMesafe=infinity;
		for(i=1;i<n;i++)
			if(ziyaretEdilen[i]==0&&mesafe[i]<minMesafe){
				v=i;
				minMesafe=mesafe[i];
			}
			u=baslangicNoktasi[v];
			// Kenar eklenir
			spanning[u][v]=mesafe[v];
			spanning[v][u]=mesafe[v];
			kenarNumarasi--;
			ziyaretEdilen[v]=1;
			// mesafe[] dizisi guncellenir
			for(i=1;i<n;i++)
				if(ziyaretEdilen[i]==0&&maliyet[i][v]<mesafe[i]){
					mesafe[i]=maliyet[i][v];
					baslangicNoktasi[i]=v;
				}
		minMaliyet=minMaliyet+maliyet[u][v];
	}
	return(minMaliyet);
}
