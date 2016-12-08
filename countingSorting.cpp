#include<bits/stdc++.h>
using namespace std;
int arr[100005],cnt[100005],res[100005];
int main(){
	int n,mx=-10000;
	cout<<"number of elements in array\n";
	cin>>n;
	memset(cnt,0,sizeof cnt);
	srand(time(NULL));
	for(int i=0;i<n;i++){
		arr[i]=rand()%100000;
		if(mx<arr[i]) mx=arr[i];
		cnt[arr[i]]++;
	}
	for(int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
	for(int i=0;i<n;i++){
		res[cnt[arr[i]]-1]=arr[i];
		cnt[arr[i]]--;
	}
	for(int i=0;i<n;i++) cout<<res[i]<<endl;
}
