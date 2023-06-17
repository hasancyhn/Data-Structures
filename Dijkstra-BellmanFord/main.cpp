// HASAN CEYHAN 20010011091 Odev1
// Bellman-Ford ve Dijkstra Algoritmalarýný kullanarak "bellmanFordInput.txt" ve 
// "dijkstraInput.txt" dosyalarýný açmak koþuluyula en kýsa yolu bulmak amaçlanmýþtýr.

//  !!!!!!!!!!!!!!!!!!!!!! DÝKKKAT !!!!!!!!!!!!!!!!!!!!!!
// Uzun sayýlarýn ekranda yer almasý sonsuz anlamýna gelmektedir.
// Mesela Dijkstra için baþngýc dugumunu 3 yaptýgýmýzda 
// D->2137483647->B sonucu sonsuz anlamina gelmektedir.

// Odevi dersde istenilen sekilde yapýp odevin açýklamasini 06.03.2023
// tarihinin aksaminda okudugum icin adým adým yazdirma islemi tam olarak yapilamamistir. 

#include<iostream>
#include<fstream>
using namespace std;
#define INF 9999;

struct node{
	int u, v;
};

int pred[1000], mesafe[1000];
bool sptset[1000];
int nv;
int graph[1000][1000];
int output[1000][1000]={0};
node edg[1000];

bool bellmanFord(int yeniKenar, int numara){
	for(int i=0; i<nv; i++){
		pred[i]  = -1;
		mesafe[i]= INF;
	}

	mesafe[numara] = 0;

	for(int i=1; i<nv; i++){
		for(int j=0; j<=yeniKenar; j++){
			node x = edg[j];
			if(mesafe[x.u]+graph[x.u][x.v] < mesafe[x.v]){
				mesafe[x.v] = mesafe[x.u]+graph[x.u][x.v];
				pred[x.v]   = x.u;
			}
		}
	}

	for(int i=0; i<=yeniKenar; ++i){
		node x = edg[i];
		if(mesafe[x.u]+graph[x.u][x.v] < mesafe[x.v])
            return false;
	}
	return true;
}

int extract_min(){
    int min_index , min=INT_MAX;
    for(int i=0;i<nv;i++){
        if(sptset[i]==true)
            continue;
        if(mesafe[i]<=min){
            min=mesafe[i];
            min_index=i;
        }
    }
    return min_index;
}

void dijkstra(int n){
    for(int i=0 ; i<nv ; ++i){
        pred[i]=0;
        sptset[i]=false;
        mesafe[i]=INT_MAX;
    }
    mesafe[n]=0;
    for(int i=0;i<nv;++i){
        int u=extract_min();
        sptset[u]=true;
        for(int j=0 ; j<nv ; ++j){
			if(graph[u][j]!=0){
				// Ziyaret edilip edilmedigini 
                if(sptset[j]==false && mesafe[u]+graph[u][j]<mesafe[j]){
                    mesafe[j]=mesafe[u]+graph[u][j];
                    pred[j]=u;
                }
            }
        }
    }
    cout<<"\nSonuc: "<<endl;
    for(int i=0;i<nv;i++){
          if(pred[i]!=i)
          cout<<char(n+'A')<<"->"<<mesafe[i]<<"->"<<char(i+'A')<<endl;
    }
}


int main() {
	while(1){
		int secim;
		cout<<"\n********************MENU********************"<<endl;
		cout<<"\nBellman-Ford Algoritmasi -------------> 1"<<endl;
		cout<<"Dijkstra Algoritmasi -----------------> 2"<<endl;
		cout<<"Cikis Icin ---------------------------> 0\n"<<endl;
		cout<<"Seciminizi Yapin:"<<endl;	cin>>secim;
		switch(secim){
			case 1: 
			{
					fstream infile;
	    			infile.open("bellmanInput.txt", ios::in);
	    			if(!infile){
	        			cout<<"Dosya acilamadi!"<<endl;
	        			return 0;
	    			}
	    			infile>>nv;
	    			for(int i=0; i<nv; i++){
	        			for(int j=0; j<nv; j++)
	            			infile>>graph[i][j];
	    			}
	
	    			cout<<"\nGirilen Cizge: "<<endl;
	    			int yeniKenar = 0;
	    			for(int i=0; i<nv; i++){
	        			for(int j=0; j<nv; j++){
	            			if(graph[i][j]){
	                			edg[yeniKenar].u = i;
	                			edg[yeniKenar].v = j;
	                			yeniKenar++;
	            			}
	            			cout<<graph[i][j]<<" ";
	        			}
	        			cout<<endl;
	    			}
	
	    			cout<<"\nKenar Sayisi: "<<yeniKenar<<endl;
	    			cout<<"\nKenarlar Asagida Yer Almaktadir:"<<endl;
				    for(int i=0; i<yeniKenar; i++){
	        			cout<<char(edg[i].u+'A')<<"->"<<char(edg[i].v+'A')<<endl;
	        		}
	
	    			int numara;
	    			cout<<"\nBaslangic Numarasini Giriniz: "<<endl;     cin>>numara;
	
	    			if(bellmanFord(yeniKenar-1, numara)){
	        			for(int i=0; i<nv; i++){
	            			if(i!=numara){
	                			cout<<char(numara+'A')<<"->"<<mesafe[i]<<"->"<<char(i+'A')<<endl;
	                		}
		    			}
	    			}
	    			else{
	    				cout<<"Negatif Dongu Bulunmakta!"<<endl;
	    			}
	    			break;
	    	}
					
			case 2:
				{
					fstream infile;
				    infile.open("dijkstraInput.txt",ios::in);
				    if(!infile){
				        cout<<"Dosya acilamadi!"<<endl;
				        return 0;
				    }
				    infile>>nv;
				    for(int i=0;i<nv;i++){
				        for(int j=0;j<nv;j++)
				            infile>>graph[i][j];
				    }
				
				    cout<<"\nGirilen Cizge:"<<endl;
				    for(int i=0;i<nv;i++){
				        for(int j=0;j<nv;j++)
				            cout<<graph[i][j]<<" ";
				        cout<<endl;
				    }
				    int ver;
				    cout<<"\nBaslangic Numarasini Giriniz: "<<endl;
				    cin>>ver;
				    dijkstra(ver);
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
