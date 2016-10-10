#include<bits/stdc++.h>
using namespace std;
int main(){
	map<int,int> mp;
	vector<pair<int,int> >vc;
	int n,tmp,arr[100];
	cin>>n;
	for(int i=0;i<n;i++) {
		scanf("%d",&tmp);
		arr[i]=tmp;
		mp[tmp]++;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it) {
		vc.push_back(make_pair((*it).second , (*it).first));
	}
	sort(vc.begin(),vc.end());
	for(int i=0;i<vc.size();i++) printf("%d %d\n",vc[i].second,vc[i].first);
}
