#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
	int index,mn,tmp,foo;
	bool f;
	for(int i=1;i<n;i++){
		tmp=arr[i];
		f=true;
		for(int j=i;j--;){
			if(tmp<arr[j]){
				foo=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=foo;
			}
			else{
				arr[j+1]=tmp;
				f=false;
				break;
			}
		}
		if(f) arr[0]=tmp;
	}
}
int main(){
	int n,arr[1000];
	//enter no of elements
	cin>>n;
	//enter elements
	for(int i=0;i<n;i++) cin>>arr[i];
	insertionSort(arr,n);
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
