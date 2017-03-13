#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,sum;
	string s,str[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	int num[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	int len=sizeof(str)/sizeof(str[0]),l;
	bool f;
	cin>>t;
	while(t--){
	    cin>>s;
	    l=s.length();
	    sum=0;
	    for(int i=0;i<l;){
	        for(int j=0;j<len;++j){
	            f=1;
	            for(int k=0;k<str[j].length();++k){
	                if(i+k<l){
	                    if(str[j][k]==s[i+k]) continue;
	                    else f=0;
	                }
	                else f=0;
	            }
	            if(f){
	                sum+=num[j];
	                i+=str[j].length();
	                break;
	            }
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
//problem link- http://www.practice.geeksforgeeks.org/problem-page.php?pid=1645
