
#include<bits/stdc++.h>
using namespace std;

void kmp(string s, string p){
	int n=s.length();
	int m=p.length();
	
	vector<int> lps(m);
	int k=0;
	for(int i=1;i<m;++i){
		while(k>0 && p[i]!=p[k])k=lps[k-1];
		if(p[i]==p[k])++k;
		lps[i]=k;
	}

	int j=0;
	for(int i=0;i<n;++i){
		while(j>0 && s[i]!=p[j])j=lps[j-1];
		if(s[i]==p[j])++j;
		if(j==m){
			int idx=i-m+1;
			cout<<s.substr(idx, m)<<endl;
			j=lps[j-1];
		}
	}

}

int main(){
	string s, p;
	cin>>s>>p;
	kmp(s, p);
}
