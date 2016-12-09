#include<bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[],int l,int r,int key){
	if(l>r) return 0;
	int mid=(l+r)>>1;
	if(key==arr[mid]) return 1;
	if(key<arr[mid]) return binarySearch(arr,l,mid-1,key);
	else return binarySearch(arr,mid+1,r,key);
}
int main(){
	int n,arr[1000];
	cout<<"enter no of elements"<<endl;
	cin>>n;
	cout<<"enter elements of sorted array"<<endl;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<"enter key to search"<<endl;
	int key;
	cin>>key;
	binarySearch(arr,0,n-1,key)?cout<<key<<" is in array":cout<<key<<" is not in array";
}
