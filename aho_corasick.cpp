
#include<bits/stdc++.h>
using namespace std;

string s[1000];
class Aho{
    struct AhoNode
    {
        int children[26];
        bool leaf;
        int parent;
        int suffixLink;
        int wordId;
        char pChar;
        int endWordLink;
        AhoNode(){
            leaf=false;
            parent=-1;
            suffixLink=-1;
            wordId=-1;
            pChar='.';
            endWordLink=-1;
            memset(children, 0, sizeof(children));
        }
    };

    vector<AhoNode> trie;
    vector<int> wordLen;
    int sz;
    int root;

public:
    Aho(){
        sz=0;
        root=0;
        trie.push_back(AhoNode());
    }

    void addString(string s, int id){
        int cur=root;
        int n=s.length();

        for(int i=0;i<n;++i){
            int child=s[i]-'a';
            if(trie[cur].children[child]==0){
                trie.push_back(AhoNode());
                trie[sz].parent=cur;
                trie[sz].pChar=s[i];
                trie[cur].children[child]=sz;

                sz++;
            }

            cur=trie[cur].children[child];
        }

        trie[cur].leaf=true;
        trie[cur].wordId=id;
        wordLen.push_back(n);
    }
    
    void buildAho(){
        queue<int> q;
        q.push(root);

        while(!q.empty()){
            int cur=q.front(); q.pop();
            buildSuffix(cur);
            for(int i=0;i<26;++i){
                if(trie[cur].children[i]!=0){
                    q.push(trie[cur].children[i]);
                }
            }
        }
    }

    void buildSuffix(int node){
        if(node==root){
            trie[node].suffixLink=root;
            trie[node].endWordLink=root;
            return;
        }

        if(trie[node].parent==root){
            trie[node].suffixLink=root;
            if(trie[node].leaf){
                trie[node].endWordLink=node;
            }
            else{
                trie[node].endWordLink=root;
            }
            return;
        }

        int cur=trie[trie[node].parent].suffixLink;
        int child=trie[node].pChar-'a';
        while(true){
            if(trie[cur].children[child]!=0){
                trie[node].suffixLink=trie[cur].children[child];
                break;
            }

            if(cur==root){
                trie[node].suffixLink=root;
                break;                
            }

            cur=trie[cur].suffixLink;
        }

        if(trie[node].leaf){
            trie[node].endWordLink=node;
        }
        else{
            trie[node].endWordLink=trie[trie[node].suffixLink].endWordLink;
        }
        
    }

    void findMatches(string text){
        int cur=root;

        for(int i=0;i<text.length();++i){
            int child=text[i]-'a';
            while(true){
                if(trie[cur].children[child]){
                    cur=trie[cur].children[child];
                    break;
                }
                if(cur==root){
                    break;
                }

                cur=trie[cur].suffixLink;
            }

            int node=cur;
            while(true){
                node=trie[node].endWordLink;
                if(node==root){
                    break;
                }
                int idx=i-wordLen[trie[node].wordId]+1;
                cout<<idx<<':'<<text.substr(idx, wordLen[trie[node].wordId])<<',';
                node=trie[node].suffixLink;
            }
        }
    }
};

int main(){
    int n;
    cin>>n;
    Aho aho;
    for(int i=0;i<n;++i){
        cin>>s[i];
        aho.addString(s[i], i);
    }
    aho.buildAho();
    string text;
    cin>>text;
    aho.findMatches(text);
}
