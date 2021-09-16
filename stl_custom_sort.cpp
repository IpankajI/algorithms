#include<bits/stdc++.h>

using namespace std;

struct Node{
  int val;
  Node* next;
  Node(int val):val(val){
    next=NULL;
  }
};

struct Comp{
  bool operator()(const Node* node1, const Node* node2)const{
    return node1->val<node2->val;
  }
}comp;

int main(){

  Node* nodes[]={new Node(4), new Node(40), new Node(-4)};
  int n=sizeof(nodes)/sizeof(nodes[0]);  


  priority_queue<Node*, vector<Node*>, Comp> pq;
  set<Node*, Comp> h;
  map<Node*, int, Comp> m;

  for(int i=0;i<n;++i){
    pq.push(nodes[i]);
    h.insert(nodes[i]);
    m[nodes[i]]=rand()%1000;
  }

  while(!pq.empty()){
    cout<<pq.top()->val<<' ';
    pq.pop();
  }
  cout<<endl;


  while(!h.empty()){
    cout<<(*h.begin())->val<<' ';
    h.erase(h.begin());
  }
  cout<<endl;

  while(!m.empty()){
    cout<<(*m.begin()).first->val<<':'<<(*m.begin()).second<<',';
    m.erase(m.begin());
  }
  cout<<endl;

  sort(nodes, nodes+n, comp);
  for(int i=0;i<n;++i){
    cout<<nodes[i]->val<<' ';
  }
  cout<<endl;

}
