#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
double pw(double x, int n){
	if(n<=0) return 1;
	if(n&1) return x*pw(x,n-1);
	double p=pw(x,n/2);
	return p*p;
}
double nthRoot(int n,int a){
	double f=a*1.0,x=1.0,pre=0.00000001;
	while((double)abs(pw(x,n)-f)>pre){
		x=x*(1-1.0/n)+a/pw(x,n-1)/n;
	}
	return x;
}
int main(){
	int n,x;
	cin>>x>>n;
	double nthroot=nthRoot(n,x);
	cout<<nthroot;
}

