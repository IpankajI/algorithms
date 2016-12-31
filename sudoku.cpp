#include <iostream>
#include<stdio.h>
using namespace std;
int mat[10][10];
bool check[10][10];
bool sCheck(int i,int j){
    int SNI=i/3,SNJ=j/3;
    SNI*=3;
    SNJ*=3;
    for(int k=0;k<3;++k){
        for(int l=0;l<3;++l){
            if((i!=SNI+k || j!=SNJ+l) && mat[i][j]==mat[SNI+k][SNJ+l]){
                return 0;
            }
        }
    }
    return 1;
}
bool cCheck(int i,int j){
    for(int k=0;k<9;++k) if(k!=i && mat[i][j]==mat[k][j]) return 0;
    return 1;
}
bool rCheck(int i,int j){
    for(int k=0;k<9;++k) if(k!=j && mat[i][j]==mat[i][k]) return 0;
    return 1;
}
bool Check(int i,int j){
    return rCheck(i,j)&&cCheck(i,j)&&sCheck(i,j);
}
int cnt=0;
bool solve(int i,int j){
    ++cnt;
    if(j>=9){
        ++i;
        j=0;
    }
    
    if(i>=9) {
        return true;
    }
    
    if(check[i][j]){
        return solve(i,j+1);
    }
    
    for(int el=1;el<=9;++el){
        mat[i][j]=el;
        if(Check(i,j) && solve(i,j+1)){
            return true;
        }
        else{
            mat[i][j]=0;
        }
    }
    return false;
}
int main() {
	//code
	int t,tmp,foo;
	scanf("%d",&t);
	while(t--){
	    for(int i=0;i<9;++i){
	        for(int j=0;j<9;++j) {
    	        scanf("%d",&mat[i][j]);
    	        check[i][j]=mat[i][j]!=0;
	        }
	    } 
	    
	    solve(0,0);
	    for(int i=0;i<9;++i){
	        for(int j=0;j<9;++j){
	            printf("%d ",mat[i][j]);
	        }
	        //printf("\n");
	    }
	    cout<<endl;
	}
	return 0;
}
