#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){	//maxHeapify
	int l=i*2+1;
	int r=l+1;
	int index=i,tmp;
	if(r<n && arr[r]>arr[index]){
		index=r;
	}
	if(l<n && arr[l]>arr[index]){
		index=l;
	}
	if(index!=i) {
		tmp=arr[index];
		arr[index]=arr[i];
		arr[i]=tmp;
		heapify(arr,n,index);
	}
}
void heapSort(int arr[],int n){
	for(int i=n>>1;i--;){
		heapify(arr,n,i);
	}
	int tmp;
	for(int i=n-1;i>0;i--){
		tmp=arr[i];
		arr[i]=arr[0];
		arr[0]=tmp;
		heapify(arr,i,0);
	}
}
int arr[1000006];
int main(){
	int n;
	memset(arr,0,sizeof arr);
	//enter no of elements
	cin>>n;
	//enter elements
	for(int i=n;i--;) cin>>arr[i];
	heapSort(arr,n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
