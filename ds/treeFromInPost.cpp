#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<string> vs;
typedef unordered_map<int,int> umap;
typedef map<long long,long long> omap;
typedef multimap<long long,long long> mmap;

#define fori(i,s,n) for(int i=(s);i<(n);++i)
#define forl(i,s,n) for(ll i=(s);i<(n);++i)
#define forir(i,n,s) for(int i=(n)-1;i>=(s);--i)
#define forlr(i,n,s) for(ll i=(n)-1;i>=(s);--i)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define all(v) v.begin(),v.end()
#define Pi(x) printf("%d", x)
#define Pl(x) printf("%lld", x)
#define os() printf(" ")
#define nl() printf("\n");
#define F first
#define S second
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265
#define INF 8944674407370955161LL
ifstream fin("input");
ofstream fout("output.txt");

typedef struct Node{
    int data;
    Node* left, * right;
}Node;

Node * newNode(int data){
    Node *n=(Node *)malloc(sizeof(Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int findPos(int in[],int start,int ending,int data){
    int i=0;
    for(i=start;i<=ending;++i){
        if(in[i]==data){
            return i;
        }
    }
    return i;
}
Node *buildUtil(int in[],int post[],int inStart,int inEnd,int &pIndex){
    if(inStart>inEnd){
        return NULL;
    }
    //cout<<pIndex<<endl;
    Node *node=newNode(post[pIndex]);
    //cout<<post[pIndex]<<endl;
   // cout<<node->data<<endl;
    pIndex--;
    // if this node has no children then return
    if(inStart==inEnd){
        return node;// if the start and end are same that means its a leaf node and have no chlildere
    }
    //find the index of this parent node in the inorder matrix
    int iIndex=findPos(in,inStart,inEnd,node->data);
    //cout<<iIndex<<endl;
    // now recursively add the left and right subtrees
    node->right=buildUtil(in,post,iIndex+1,inEnd,pIndex);
    node->left=buildUtil(in,post,inStart,iIndex-1,pIndex);
    return node;
}
Node *buildTree(int in[],int post[],int n){
    int pIndex=n-1;
    return buildUtil(in,post,0,n-1,pIndex);
}
void printInorder(Node *root){
    if(root!=NULL){
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}
int main()
{
    int n;
    fin>>n;
    int post[n];
    int in[n];
    fori(i,0,n){
        fin>>in[i];
    }
    fori(i,0,n){
        fin>>post[i];
    }

    Node *root=buildTree(in,post,n);
    printInorder(root);// to test
    return 0;
}

