#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) < (b) ? (a) : (b))

struct node{
  int unmatchedOpen, unmatchedClosed;

  void assignLeaf(char p){
    if(p=='(')
      unmatchedOpen = 1, unmatchedClosed = 0;
    else
      unmatchedOpen = 0, unmatchedClosed = 1;
  }

  void merge(node &l, node &r){
    int newMatch = min(l.unmatchedOpen,r.unmatchedClosed);
    unmatchedOpen = l.unmatchedOpen + r.unmatchedOpen - newMatch;
    unmatchedClosed = l.unmatchedClosed + r.unmatchedClosed - newMatch;
  }

  bool getVal(){
    return unmatchedOpen==0 && unmatchedClosed==0;
  }
};

vector<char> arr(32768);
vector<node> tree(65536);

void build(int root,int left,int right){
  if(left>right)
    return;
  if(left==right){
    tree[root].assignLeaf(arr[left]);return;
  }

  build(root<<1,left, (left+right)/2);
  build((root<<1) + 1, 1 + (left+right)/2, right);

  tree[root].merge(tree[root<<1],tree[(root<<1)+1]);
}


void update(int root, int left,int right,int i,int j){
  if(left > right || left > j || right < i)
    return;

  if(left==right){
    if(arr[left]=='('){
      arr[left] = ')';
      tree[root].assignLeaf(')');
    }
    else{
      arr[left] = '(';
      tree[root].assignLeaf('(');
    }
    return;
  }

  update(root<<1,left,(left+right)/2,i,j);
  update((root<<1)+1,1 + (left+right)/2, right,i,j);

  tree[root].merge(tree[root<<1],tree[1+(root<<1)]);
}

int main(){
  int n;int x=1;
  while(cin>>n){
    arr.clear();
    tree.clear();
    fr(i,0,n)
      cin>>arr[i];

    build(1,0,n-1);

    int m,c;

    cin>>m;
    cout<<"Test "<<x++<<":"<<endl;
    fr(i,0,m){
      cin>>c;
      if(c==0){
	cout<<(tree[1].getVal() ? "YES" : "NO")<<endl;
      }
      else{
	update(1,0,n-1,c-1,c-1);
      }
    }
  }
}
      
	
  

    
