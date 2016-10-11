#include<bits/stdc++.h>
using namespace std;
int heap[100000];
static int index=0;
void insertHeapify(int in){
	int i=in>>1;
	if(i==0) return;
	if(heap[in]>heap[i]){
		int tmp=heap[in];
		heap[in]=heap[i];
		heap[i]=tmp;
		insertHeapify(i);
	}	
}
void insert(int x){
	index++;
	heap[index]=x;
	insertHeapify(index);
}
void delHeapify(int in=1){
	int x=in<<1;
	if(in>index) return;
	else if(heap[x]>heap[x+1]){
		int tmp=heap[x];
		heap[x]=heap[in];
		heap[in]=tmp;
		delHeapify(x);
	}
	else{
		x++;
		int tmp=heap[x];
		heap[x]=heap[in];
		heap[in]=tmp;
		delHeapify(x);
	}
}
void del(){
	heap[1]=heap[index];
	heap[index]=0;
	delHeapify();
}
int main(){
	int n,m,x,action;
	cout<<"enter number of operations to be performed= insertions + deletion"<<endl;
	cin>>n;
	for(int i=n;i--;){
		cout<<"enter 1 for insertion 0 for deletion"<<endl;
		cin>>action;
		if(action!=0 && action!=1) {
			i++;
			//cout<<"enter 1 for insertion 0 for deletion"<<endl;
			continue;
		}
		if(action==1){
			cout<<"enter positive number to insert"<<endl<<endl;
			cin>>x;
			insert(x);
			cout<<"max heap element: "<<heap[1]<<endl;
		}
		else{
			cout<<"max heap element before deletion: "<<heap[1]<<endl;
			del();
			cout<<"max heap element after deletion: "<<heap[1]<<endl;
		}
	}
}
