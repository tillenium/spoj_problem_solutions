//this is a problem of lazy propapagtion
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

struct node{
  int sum;
  void merge(node &l, node &r){
    sum = l.sum + r.sum;
  }
};

int arr[100000];
node tree[131080];
vector<int> lazy(131080,0);

void update_tree(int root, int a,int b,int i,int j,int value){
    cout<<root<<" "<<a<<" "<<b<<" "<<endl;
  if(lazy[root] != 0){
    tree[root].sum += lazy[root];
    if(a!=b){
      lazy[root<<1] += lazy[root];
      lazy[(root<<1)+1] += lazy[root];
    }
    lazy[root] = 0;
  }

  if(a>b || a > j || b < i)
    return ;

  if(a>=i && b<= j){
    tree[root].sum += value;

    if(a!=b){
      lazy[root<<1] += value;
      lazy[(root<<1)+1] += value;
    }
    return;
  }

  update_tree(root<<1,a,(a+b)/2,i,j,value);
  update_tree((root<<1)+1,(a+b)/2 + 1,b,i,j,value);

  tree[root].merge(tree[root<<1],tree[(root<<1)+1]);
}


node query(int root,int left, int right,int i,int j){

  if(left > right || left > j || right < i){
    node n; n.sum = 0;
    return n;
  }

  if(lazy[root]){
    tree[root].sum += lazy[root];

    if(left!=right){
      lazy[root<<1] += lazy[root];
      lazy[1 + (root<<1)] += lazy[root];
    }

    lazy[root] = 0;
  }

  if(left >= i && right <= j)
    return tree[root];

  node l = query(root<<1, left, (left+right)/2, i, j);
  node r = query((root<<1)+1, (left+right)/2 + 1, right,i,j);

  tree[root].merge(l,r);
  return tree[root];
}

int main(){
  int t,n,c;
  cin>>t;
  while(t--){
    cin>>n>>c;
    int treesize  = 1<<((int)log2(n) +2);
    cout<<treesize<<endl;
    fr(i,0,treesize+1){
      tree[i].sum = 0;
    }

    int x,y,z,v;
    fr(i,0,c){
      cin>>x;

      if(x){
	cin>>y>>z;
	cout<<query(1,0,n-1,y--,z--).sum<<endl;
      }
      else{
	cin>>y>>z>>v;
	update_tree(1,0,n-1,y--,z--,v);
	fr(i,0,treesize+1)
	  cout<<tree[i].sum<<" ";
      }
    }
  }
}
