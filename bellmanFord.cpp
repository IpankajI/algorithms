#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=1e9+5;
int G[N*10][3],D[N];
void bellmanFord(int V,int E){
	for(int i=V-1;i--;){
		for(int j=E;j--;){
			if(D[G[j][1]]>D[G[j][0]]+G[j][2]) D[G[j][1]]=D[G[j][0]]+G[j][2];
		}
	}
}
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=m;i--;){
		scanf("%d %d %d",&u,&v,&w);
		G[i][0]=u;
		G[i][1]=v;
		G[i][2]=w;
	}
	for(int i=0;i<N;i++){
		D[i]=INF;
	}
	D[1]=0;
	bellmanFord(n,m);
	for(int i=2;i<=n;i++) printf("%d ",D[i]);
}
