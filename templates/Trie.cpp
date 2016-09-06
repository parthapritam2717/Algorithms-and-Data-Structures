#include <iostream>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;


/*This is the structure for the Trie Node ii will contain the map of all the characters which are contained in the node with the
address of the node. Bool will keep details if it is the end of a work or not */



typedef struct TrieNode{
    struct TrieNode *child[26];
    bool word_end;
}TrieNode;


TrieNode *newNode(){
    TrieNode *n=(TrieNode *)malloc(sizeof(TrieNode));
    memset(n->child,0,sizeof(n->child));
    n->word_end=false;
    return n;
}

TrieNode *constructTrie(vector<string> &data){
    TrieNode *root=newNode();
    TrieNode *n=root;
    int l=data.size();
    for(int i=0;i<l;++i){
        string s=data[i];
        n=root;
        for(int j=0;j<s.size();++j){
            if((n->child)[s[j]-'a']==0){
                // insert s[j] at this node and give a new node
                if(j!=(s.size()-1)){
                    // needto add true for the
                    TrieNode *temp=newNode();
                    (n->child)[s[j]-'a']=temp;
                    n=temp;
                }
                else if(j==(s.size()-1)){
                    TrieNode *temp=newNode();
                    temp->word_end=1;
                    (n->child)[s[j]-'a']=temp;
                    n=temp;
                }

            }
            else{
                // character already present but check if j==s.size()-1 then label it as true
                if(j==(s.size()-1)){
                    n->word_end=true;
                }
                // if already present then we will have to find the next value of n as diffrenet
                n=((n->child)[s[j]-'a']);
            }
        }
    }
    return root;
}
/*using this method we will try to find the desired string from the trie if it is found then we will print yes else no*/
bool TrieSearch(TrieNode *root,string s){
    TrieNode *n=root;
    for(int j=0;j<s.size();++j){
         if((n->child)[s[j]-'a']==0){
        // cout<<"hello";
            return 0;
        }
        else{
          //  cout<<s[j]<<endl;
            n=((n->child)[s[j]-'a']);
        }
    }
    if(n->word_end==1){
        return 1;
    }
    return 0;

}

int main(){
    int n;
    cin>>n;
    vector<string> data;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        data.push_back(s);
    }

    TrieNode *root=constructTrie(data);
    string item;
    cin>>item;
    if(TrieSearch(root,item)){
            cout<<item<<" found!!"<<endl;
    }
    else{
            cout<<item<<" Not found!!"<<endl;
    }
    return 0;
}







