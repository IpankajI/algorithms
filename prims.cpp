#include<bits/stdc++.h>
using namespace std;
const int N=10005;
bool included[N];
vector<pair<int,int> > vc[N];
long long prims(){
	long long res=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > prq;
	pair<int,int> pr;
	prq.push(make_pair(0,1));
	while(!prq.empty()){
		pr=prq.top();
		prq.pop();
		if(included[pr.second]) continue;
		included[pr.second]=1;
		res+=pr.first;
		for(int i=vc[pr.second].size();i--;){
			if(!included[vc[pr.second][i].second]){
				prq.push(make_pair(vc[pr.second][i].first,vc[pr.second][i].second));
			}
		}
	}
	return res;
}
int main(){
	int n,m,u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=m;i--;){
		scanf("%d %d %d",&u,&v,&w);
		vc[u].push_back(make_pair(w,v));
	}
	printf("%lld",prims());
}
