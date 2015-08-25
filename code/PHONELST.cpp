#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

struct tnode{
  int words;
  int prefix;
  tnode *child[10];
};

struct trie{
  tnode *root;
  int count;
};

tnode *createNode(){
  tnode *t = new tnode;
  if(t){
    t->words = 0;
    t->prefix = 0;
    fr(i,0,10){
      t->child[i] = NULL;
    }
  }
  return t;
}


void initialize(trie *p){
  p->root = createNode();
  p->count = 0;
};

//insert a word (number here) inside trie)
void insert(trie *p,string s){
  int len = s.size();
  tnode *mov = p->root;
  p->count++;
  fr(i,0,len){
    int ind = (int) (s[i]-'0');
    if(!mov->child[ind])
      mov->child[ind] = createNode();
    mov = mov->child[ind];
    (mov->prefix)++;
  }
  mov->words =  p->count;
}

int countPrefixes(trie *p, string s){
  tnode *mov = p->root;
  fr(i,0,s.size()){
    int ind = s[i] - '0';

    if(!mov->child[ind])
      return 0;
    
    mov = mov->child[ind];
  }

  return mov->prefix;
}


int main(){
  int t,n,s;
  cin>>t;
  while(t--){
    cin>>n;
    trie t;
    int flag = 0;
    initialize(&t);

    vector<string> ph(n);
    fr(i,0,n)
      cin>>ph[i];

    sort(ph.begin(),ph.end());

    for(int i=n-1;i>=0;i--){
      insert(&t,ph[i]);
      if(countPrefixes(&t,ph[i]) > 1){
	flag = 1;
	break;
      }
  }
    if(flag)
      cout<<"NO\n";
    else
      cout<<"YES\n";
  }
    
}


