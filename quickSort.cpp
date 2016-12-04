#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int r){
	int in=0,key=arr[r],tmp;
	for(int i=0;i<r;i++){
		if(arr[i]<key){
			tmp=arr[in];
			arr[in]=arr[i];
			arr[i]=tmp;
			in++;
		}
	}
	arr[r]=arr[in];
	arr[in]=key;
	return in;
}
void quickSort(int arr[],int l,int r){
	if(l<r){
		int in=partition(arr,l,r);
		quickSort(arr,l,in-1);
		quickSort(arr,in+1,r);
	}
}
int main(){
	int t,arr[1000],tmp,n;
	cin>>n;
	srand(time(NULL));
	for(int i=n;i--;) arr[i]=rand();
	quickSort(arr,0,n-1);
	for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}
