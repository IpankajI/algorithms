#include<bits/stdc++.h>
using namespace std;
void pythagorianTriplet(int arr[],int n,int sum){
	bool check[10000]={0};
	for(int i=n;i--;){
		int tmp=sum-arr[i];
		if(check[tmp] && tmp>0){
			cout<<int(sqrt(tmp))<<" "<<int(sqrt(arr[i]))<<" "<<int(sqrt(sum))<<endl;
		}
		check[arr[i]]=1;
	}
}
int main(){
	int n,arr[1000],sum;
	cin>>n;
	for(int i=n;i--;){
		cin>>arr[i];
		arr[i]=arr[i]*arr[i];
	}
	for(int i=n;i--;)
	pythagorianTriplet(arr,n,arr[i]);
}
