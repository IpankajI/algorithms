#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int r){
	int mid=(l+r)>>1;
	int tmp[10000],in=mid+1,index=0,ll=l;
	while(l<=mid && in<=r){
		if(arr[l]<=arr[in]) tmp[index++]=arr[l++];
		else tmp[index++]=arr[in++];
	}
	for(;l<=mid;l++) tmp[index++]=arr[l];
	for(;in<=r;in++) tmp[index++]=arr[in];
	index=0;
	for(;ll<=r;ll++) arr[ll]=tmp[index++];
}
void mergeSort(int arr[],int l,int r){
	if(l>=r) return;
	int mid=(l+r)>>1;
	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	merge(arr,l,r);
}
int n,arr[10000];
int main(){
	cin>>n;
	srand(time(NULL));
	for(int i=n;i--;) arr[i]=rand();
	mergeSort(arr,0,n-1);
	for(int i=n;i--;) cout<<arr[i]<<endl;
}
