#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
int size,m,n;

struct node{
  long sum,pre,suf,ans;
  void merge(node &l, node &r){
    sum = l.sum + r.sum;
    pre = max(l.pre,l.sum + r.pre);
    suf = max(l.suf + r.sum , r.suf);
    ans = max(max(max(max(max(l.ans,r.ans),l.suf + r.pre),suf),sum),pre);
  }
  void create(int val){
    sum=pre=suf=ans=val;
  }
  void copy(node &s){
    sum = s.sum;pre=s.pre;suf=s.suf;ans=s.ans;
  }
};

vector<node> tree;
vector<int> arr;

void build(int root,int left,int right){
  if(left>right)
    return;
  if(left==right){
    tree[root].create(arr[left]);
    return;
  }
  build(root<<1,left,(left+right)/2);
  build((root<<1)+1,(left+right)/2+1,right);
  tree[root].merge(tree[root<<1],tree[(root<<1)+1]);
}

void update(int root,int left, int right, int i,int j,int val){
  if(left>j || right < i || left > right)
    return;

  if(left==right){
    tree[root].create(val);
    return;
  }

  update(root<<1,left,(left+right)/2,i,j,val);
  update((root<<1)+1,(left+right)/2+1,right,i,j,val);

  tree[root].merge(tree[root<<1],tree[(root<<1)+1]);
}

node query(int root, int left, int right, int i,int j){

  if(left >= i && right <= j)
    return tree[root];

  int mid = (left+right)/2;
  if(i>mid)
    return query((root<<1)+1,mid+1,right,i,j);
  if(j <= mid)
    return query(root<<1,left,mid,i,j);
  
  node  l = query(root<<1,left,(left+right)/2,i, j);
  node  r = query((root<<1) + 1,(left+right)/2 + 1, right,i,j);

  node t;t.copy(tree[root]);
  t.merge(l,r);

  return t;
}
  

int main(){
  cin>>size;
  //  n = 1<< ((int)log2(size) + 1);
  arr.resize(size);tree.resize(100000);

  fr(i,0,size)
    cin>>arr[i];
  build(1,0,size-1);

  cin>>m;
  int a,b,c;
  fr(i,0,m){
    cin>>a>>b>>c;

    switch(a){
    case 0:
      b--;
      update(1,0,size-1,b,b,c);
      break;

    case 1:
      b--;c--;

      cout<<query(1,0,size-1,b,c).ans<<endl;
      break;
    }
  }
  
}
  
  
