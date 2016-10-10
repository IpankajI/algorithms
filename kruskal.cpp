#include<bits/stdc++.h>
using namespace std;
const int N=3005;
pair<int,pair<int,int> > pr[(N*(N-1))>>1];
int node[N];
void init(){
	for(int i=0;i<N;i++) node[i]=i;
}
int root(int in){
	while(in!=node[in]){
		in=node[node[in]];
	}
	return in;
}
void _union(int a,int b){
	int ra=root(a),rb=root(b);
	node[ra]=node[rb];
}
long long kruskal(int m){
	long long res=0;
	for(int i=0;i<m;i++){
		if(root(pr[i].second.second)!=root(pr[i].second.first)){
			res+=pr[i].first;
			_union(pr[i].second.second,pr[i].second.first);
		}
	}
	return res;
}
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=m;i--;){
		scanf("%d %d %d",&u,&v,&w);
		pr[i]=make_pair(w,make_pair(u,v));
	}
	sort(pr,pr+m);
	init();
	printf("%lld",kruskal(m));
}
