#include <stdio.h>
#include <string>
#include<set>
#include<iostream>
using namespace std;
void permut(string str,int l,int r){
	if(r<=l) cout<<str<<endl;
	else{
		set<char> et;
		int tmp;
		for(int i=l;i<=r;i++){
			tmp=et.size();
			et.insert(str[i]);
			string st=str;
			st[l]=str[i];
			st[i]=str[l];
			if((str[l]==str[i] && i!=l)|| tmp==et.size())
			continue;
			else permut(st,l+1,r);
		}
	}
}
int main ()
{
  permut("aabacd",0,5);
}
