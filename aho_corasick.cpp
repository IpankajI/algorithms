#include<bits/stdc++.h>


using namespace std;

class Aho
{
private:
    struct AhoNode
    {
        map<int, int> children;
        char ch;
        int suffixLink;
        int wordEnd;
        bool leaf;
        int parent;
        int wordId;
        AhoNode(){
            ch='.';
            suffixLink=-1;
            wordEnd=-1;
            leaf=false;
            parent=-1;
            wordId=-1;
        }
    };
    
    vector<AhoNode> trie;
    vector<int> wordLen;
    int root;
    int sz;

    void buildLink(int node){
        if(node==root){
            trie[node].suffixLink=root;
            trie[node].wordEnd=root;
            return;
        }

        if(trie[node].parent==root){
            trie[node].suffixLink=root;
            if(trie[node].leaf){
                trie[node].wordEnd=node;
            }
            else{
                trie[node].wordEnd=trie[trie[node].suffixLink].wordEnd;
            }
            return;
        }

        int next=trie[trie[node].parent].suffixLink;
        int ch=trie[node].ch;

        while(true){
            if(trie[next].children.count(ch)){
                trie[node].suffixLink=trie[next].children[ch];
                break;
            }

            if(next==root){
                trie[node].suffixLink=root;
                break;
            }

            next=trie[next].suffixLink;
        }

        if(trie[node].leaf){
            trie[node].wordEnd=node;
        }
        else{
            trie[node].wordEnd=trie[trie[node].suffixLink].wordEnd;
        }
    }

public:
    Aho(){
        root=0;
        trie.push_back(AhoNode());
        sz=1;
    }

    void add(string s, int id){
        int cur=root;

        for(int i=0;i<s.length();++i){
            int ch=s[i];
            if(trie[cur].children.count(ch)==0){
                trie.push_back(AhoNode());
                trie[sz].ch=s[i];
                trie[sz].parent=cur;
                trie[cur].children[ch]=sz;
                sz++;
            }
            cur=trie[cur].children[ch];
        }
        trie[cur].leaf=true;
        trie[cur].wordId=id;
        wordLen.push_back(s.length());
    }

    void buildAho(){
        queue<int> q;
        q.push(root);

        while(!q.empty()){
            int node=q.front(); q.pop();
            buildLink(node);
            for(map<int, int>::iterator it=trie[node].children.begin(); it!=trie[node].children.end();++it){
                q.push(it->second);
            }
        }

    }

    void findMatches(string text){
        int cur=root;

        for(int i=0;i<text.length();++i){
            int ch=text[i];
            
            while(true){
                if(trie[cur].children.count(ch)){
                    cur=trie[cur].children[ch];
                    break;
                }
                if(cur==root){
                    break;
                }
                cur=trie[cur].suffixLink;
            }

            int found=cur;

            while(true){
                int wordEnd=trie[found].wordEnd;
                if(wordEnd==root){
                    break;
                }
                int len=wordLen[trie[wordEnd].wordId];
                int idx=i-len+1;
                cout<<text.substr(idx, len)<<' ';
                found=trie[found].suffixLink;
                
            }

        }
    }

};


int main(){
    string s[]={"cat", "mat", "example", "random", "cat"};

    int n=sizeof(s)/sizeof(s[0]);
    Aho aho;
    for(int i=0;i<n;++i){
        aho.add(s[i], i);
        // aho.addString(s[i]);
        
    }
    aho.buildAho();

    string text="dsadscardsadamatdsecatdfhwgaedhfrandomdaexamplefdsjkfh";
    aho.findMatches(text);
    //output- mat cat random example
    
}