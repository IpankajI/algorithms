#include <bits/stdc++.h>
using namespace std;
bool board[11][11];
int n;
bool Move(int i,int j){
    for(int k=0;k<n;++k) if(k!=j && board[i][k]){
        return false;
    }
    for(int k=0;k<n;++k) if(k!=i && board[k][j]){
        return false;
    }
    int k=i,l=j;
    while(k>0 && l>0){
        --k;
        --l;
        if(board[k][l]) return false;
    }
    k=i,l=j;
    while(k<n-1 && l<n-1){
        ++k;
        ++l;
        if(board[k][l]) return false;
    }
    k=i,l=j;
    while(k>0 && l<n-1){
        --k;
        ++l;
        if(board[k][l]) return false;
    }
    k=i,l=j;
    while(k<n-1 && l>0){
        ++k;
        --l;
        if(board[k][l]) return false;
    }
    return true;
}
int cnt=0;
stack<int> sols[1000];
bool Solve(int column,int queens){
    if(queens>n){
        cout<<"[";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;++j){
                if(board[j][i])cout<<j+1<<" ";
            }
        }
        cout<<"] ";
        ++cnt;
        return true;
    }
    bool f=false;
    for(int row=0;row<n;++row){
        board[row][column]=1;
        if(Move(row,column) && Solve(column+1,queens+1)){
            f=true;
        }
        board[row][column]=0;
    }
    return f;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    cin>>n;
	    cnt=0;
	    memset(board,0,sizeof(board[0][0])*n*n);
	    Solve(0,1);
	    if(cnt==0){
	        cout<<-1;
	    }
	    cout<<endl;
	}
	return 0;
}
//problem link-http://www.practice.geeksforgeeks.org/problem-page.php?pid=1521
