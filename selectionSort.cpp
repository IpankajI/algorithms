#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
	int index,mn,tmp;
	for(int i=0;i<n;i++){
		mn=1e9;
		for(int j=i;j<n;j++){
			if(mn>arr[j]){
				mn=arr[j];
				index=j;
			}
		}
		tmp=arr[i];
		arr[i]=arr[index];
		arr[index]=tmp;
	}
}
int main(){
	int n,arr[1000];
	cout<<"enter no of elements\n";
	cin>>n;
	srand(time(NULL));
	for(int i=0;i<n;i++) arr[i]=rand();
	selectionSort(arr,n);
	for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}
