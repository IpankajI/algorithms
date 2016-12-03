#include<bits/stdc++.h>
using namespace std;
const int N=100;
int graph[N][N];
int dist[N];
bool done[N];
int minD(int n){
	int mn=INT_MAX,index;
	for(int i=0;i<n;i++){
		if(!done[i]&& mn>dist[i]) mn=dist[i],index=i;
	}
	return index;
}
void dijkshtra(int s,int v){
	for(int i=v+1;i--;) done[i]=0,dist[i]=INT_MAX;
	dist[s]=0;
	for(int i=0;i<v;i++){
		int u=minD(v);
		done[u]=1;
		for(int j=0;j<v;j++){
			if(!done[j]  && graph[u][j] && dist[j]>dist[u]+graph[u][j]){
				dist[j]=dist[u]+graph[u][j];
			}	
		}
	}
}
int main(){
	int u,v,m,foo,n,w,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cin>>graph[i][j];
		}
		cin>>m;
		dijkshtra(m,n);
		for(int i=0;i<n;i++) cout<<dist[i]<<" ";
		cout<<endl;
	}
	
}
