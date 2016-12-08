#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[],int n){
	bool f;
	for(int i=0;i<n;i++){
		f=true;
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
				f=0;
			}
		}
		if(f) break;
	}
}
int main(){
	int n,arr[1000];
	cout<<"enter no of elements\n";
	cin>>n;
	srand(time(NULL));
	for(int i=0;i<n;i++) arr[i]=rand();
	bubbleSort(arr,n);
	for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}
