#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int pos[N];

struct node
{
  int rank[2];
  int index;
  bool operator < (const node& b) const{
    if (rank[0] == b.rank[0])
      return rank[1] < b.rank[1];
    return rank[0] < b.rank[0];
  }
}nodes[N];

vector<int> SuffixArray(string& s){
  vector<int> v;
  int len = s.length();

  for(int i = 0; i < len; ++i){
    nodes[i].rank[0] = s[i] - 'a';
    nodes[i].rank[1] = i + 1 < len ? s[i + 1] - 'a' : -1;
    nodes[i].index = i;
  }
  sort(nodes, nodes + len);

  for(int step = 4; step < 2*len; step<<=1){
    int rank = 0;
    int pRank = nodes[0].rank[0];
    nodes[0].rank[0] = 0;
    pos[nodes[0].index] = 0;

    for(int i = 1; i < len; ++i){
      if( nodes[i].rank[0] == pRank && nodes[i].rank[1] == nodes[i-1].rank[1]){
        pRank = nodes[i].rank[0];
        nodes[i].rank[0] = rank;
      }
      else{
        pRank = nodes[i].rank[0];
        nodes[i].rank[0] = ++rank;
      }
      pos[nodes[i].index] = i;
    }

    for( int i = 0; i < len; ++i){
      int nIndex = nodes[i].index + step/2;
      nodes[i].rank[1] = nIndex < len ? nodes[pos[nIndex]].rank[0] : -1;
    }

    sort(nodes, nodes + len);
  }

  for(int i = 0; i < len; ++i)
    v.push_back(nodes[i].index);
  return v;
}

vector<int> LCP(string& s){
  // kasai algorithm
  vector<int> a = SuffixArray(s);
  int len = s.length();
  vector<int> rank(len, 0);
  vector<int> lcpa(len, 0);
  for(int i = 0; i < len; ++i)
    rank[a[i]] = i;

  int lcp = 0;
  for(int i = 0; i < len; ++i){
    if(rank[i] == len -1){
      lcp = 0;
      continue;
    }

    int j = a[rank[i] + 1];
    while(i + lcp < len && j + lcp < len && s[i + lcp] == s[j + lcp])
      ++lcp;
    lcpa[rank[i]] = lcp;

    if(lcp)
      --lcp;
  }

  return lcpa;
}

int main(){
  string s;
  while(cin>>s){
    vector<int> v = LCP(s);
    for(int i =0 ; i < v.size() ; ++i)
      cout<<v[i];
    cout<<endl;
  }
}