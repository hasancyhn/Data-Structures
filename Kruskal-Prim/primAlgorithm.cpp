#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
#define infinity 9999
#define MAX 20
 
using namespace std;
 
int G[MAX][MAX],spanning[MAX][MAX],n;
 
int prims();
 
int main(){
	int i, j, toplamMaliyet;
	//cout<<"Kose Sayisini Giriniz: "<<endl;	cin>>n;
	printf("Kose Sayisini Giriniz: ");	scanf("%d",&n);
	//cout<<"Adjacency Matrix Degerlerini Giriniz:\n";
	printf("\nAdjacency Matrix Degerlerini Giriniz:\n");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			//cin>>G[i][j];
			scanf("%d", &G[i][j]);
			toplamMaliyet = prims();
			printf("\nSpanning Tree Matrix:\n");
			for(i=0; i<n; i++){
				//cout<<"\n";
				printf("\n");
				for(j=0; j<n; j++)
					//cout<<"%d\t"<<spanning[i][j]<<endl;
					printf("%d\t",spanning[i][j]);
			}				
	//cout<<"\n\nToplam Maliyet = %d"<<toplamMaliyet<<endl;
	printf("\n\nToplam Maliyet = %d", toplamMaliyet);
	return 0;
}
 
int prims(){
	int cost[MAX][MAX];
	int u, v, min_distance, distance[MAX], from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;
	//create cost[][] matrix,spanning[][]
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(G[i][j]==0)
			cost[i][j]=infinity;
			else
				cost[i][j]=G[i][j];
				spanning[i][j]=0;
		}
		
	//initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	for(i=1;i<n;i++){
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	
	min_cost=0; //cost of spanning tree
	no_of_edges=n-1; //no. of edges to be added
	while(no_of_edges>0){
		//find the vertex at minimum distance from the tree
		min_distance=infinity;
		for(i=1;i<n;i++)
			if(visited[i]==0&&distance[i]<min_distance){
				v=i;
				min_distance=distance[i];
			}
			u=from[v];
			//insert the edge in spanning tree
			spanning[u][v]=distance[v];
			spanning[v][u]=distance[v];
			no_of_edges--;
			visited[v]=1;
			//updated the distance[] array
			for(i=1;i<n;i++)
				if(visited[i]==0&&cost[i][v]<distance[i]){
					distance[i]=cost[i][v];
					from[i]=v;
				}
		min_cost=min_cost+cost[u][v];
	}
	return(min_cost);
}
