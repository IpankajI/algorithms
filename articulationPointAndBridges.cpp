#include<bits/stdc++.h>
using namespace std;
const int N=100;
int parent[N],disc[N],low[N],tim;
vector<int> adj[N];
bool visited[N];
vector<pair<int ,int> > vc;
vector<int> AP;
void dfsAP(int s){
	visited[s]=1;
	disc[s]=low[s]=++tim;
	int child=0;
	for(int i=adj[s].size();i--;){
		if(!visited[adj[s][i]]){
			++child;
			parent[adj[s][i]]=s;
			dfsAP(adj[s][i]);
			low[s]=min(low[s],low[adj[s][i]]);
			if(parent[s]==-1 && child>1) AP.push_back(s);//[s]=1;
			if(low[adj[s][i]]>disc[s]) {
				if(s<adj[s][i]) vc.push_back(make_pair(s,adj[s][i]));
				else vc.push_back(make_pair(adj[s][i],s));
			}
			if(parent[s]!=-1 && low[adj[s][i]]>=disc[s])AP.push_back(s);// AP[s]=1;
		}
		else if(parent[s]!=adj[s][i]){
			low[s]=min(low[s],disc[adj[s][i]]);
		}
	}
}
int main(){
	//freopen("in.txt","w",stdin);
	int n,m,v,u;
	scanf("%d %d",&n,&m);
	memset(parent,-1,sizeof parent);
	memset(visited,0,sizeof visited);
	for(int i=m;i--;){
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfsAP(0);
	printf("%d\n",AP.size());
	sort(AP.begin(),AP.end());
	for(int i=0;i<AP.size();i++) printf("%d ",AP[i]);
	printf("\n");
	sort(vc.begin(),vc.end());
	printf("%d\n",vc.size());
	for(int i=0;i<vc.size();i++) printf("%d %d\n",vc[i].first,vc[i].second);
}
