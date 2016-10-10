#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	int height;
};
Node* newNode(int x){
	Node * node=new Node;
	node->data=x;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}
int Height(Node* node){
	if(node==NULL) return 0;
	else return node->height;
}
int balance(Node* node){
	return Height(node->left)-Height(node->right);
}
Node* rotateLeft(Node* node){
	Node* temp=node->right;
	node->right=temp->left;
	temp->left=node;
	node->height=max(Height(node->left),Height(node->right))+1;
	temp->height=max(Height(temp->left),Height(temp->right))+1;
	return temp;
}
Node* rotateRight(Node* node){
	Node* temp=node->left;
	node->left=temp->right;
	temp->right=node;
	node->height=max(Height(node->left),Height(node->right))+1;
	temp->height=max(Height(temp->left),Height(temp->right))+1;
	return temp;
}
Node* AVL(Node* node,int x){
	if(node==NULL) return newNode(x);
	if(x>node->data) node->right= AVL(node->right,x);
	else node->left=AVL(node->left,x); 
	int bf=balance(node);
	if(bf>1 && x<node->left->data){
		return rotateRight(node);
	}
	else if(bf<-1 && x>node->right->data) return rotateLeft(node);
	else if(bf>1 && x>node->left->data){
		node->left=rotateLeft(node->left);
		return rotateRight(node);
	}
	else if(bf<-1 && x<node->right->data){
		node->right=rotateRight(node->right);
		return rotateLeft(node);
	}
	return node;
}
void inorder(Node* node){
	if(node==NULL) return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}
int main(){
	int n,x;
	Node*node=NULL;
	cin>>n;
	while(n--){
		cin>>x;
		node=AVL(node,x);
		inorder(node);
		cout<<endl;
	}
}
