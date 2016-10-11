#include<stdio.h>
#include<vector>
#include<iostream>
#include<set>
#define ll long long
using namespace std;
const ll INF=1e9,V=1000005;
vector<pair<int,int> > vc[V];
ll dist[V];
bool done[V];
set<pair<ll,int> > pq;
pair<ll,int> pr;
void Dijkshtra(){
	for(int i=V;i--;) dist[i]=INF;
	while(!pq.empty()){
		 pr=*pq.begin();
		 pq.erase(pr);
		 done[pr.second]=true;
		 for(int i=vc[pr.second].size();i--;){
			if(!done[vc[pr.second][i].first]){
				if(dist[vc[pr.second][i].first]>(pr.first+vc[pr.second][i].second))
				dist[vc[pr.second][i].first]=pr.first+vc[pr.second][i].second;
				pq.insert(make_pair(dist[vc[pr.second][i].first],vc[pr.second][i].first));
			}
		}
	}
}
int main(){
	int n,m,u,v,w,s;
	scanf("%d %d",&n,&m);
	for(int i=m;i--;){
		scanf("%d %d %d",&u,&v,&w);
		vc[u].push_back(make_pair(v,w));
	}
	s=1; // sourece vertex is 1
	pq.insert(make_pair(0,s));
	dist[s]=0;
	Dijkshtra();
	for(int i=2;i<=n;i++)
	printf("%lld ",dist[i]);
}
