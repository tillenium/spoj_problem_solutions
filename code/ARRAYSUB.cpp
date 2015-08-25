#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

struct node{
  int val;
  void merge(node &l, node &r){
    val = max(l.val,r.val);
  }
};

int arr[1000000];
node tree[1048576];

void build(int root,int left,int right){
  if(left>right)
    return;
  if(left==right){
    tree[root].val = arr[left];return;
  }
  build(root<<1, left,(left+right)/2);
  build((root<<1)+1,(left+right)/2 + 1, right);
  tree[root].merge(tree[root<<1],tree[(root<<1)+1]);
}

int query(int root, int left,int right,int i,int j){
  if(left > right || left > j || right < i)
    return -1;
  if(i<=left && right<= j)
    return tree[root].val;
  int q1 = query(root<<1, left,(left+right)/2, i,j);
  int q2 = query((root<<1) + 1, (left+right)/2+1, right,i,j);
  return max(q1,q2);
}

int main(){
  int size;cin>>size;
  //arr.clear();arr.resize(size);
  //int n = 1048576;//1<<((int)log2(size) + 1);
  //cout<<n;
  //tree.clear();tree.resize(n);

  fr(i,0,size)
    cin>>arr[i];
  int k;cin>>k;
  build(1,0,size-1);
  
  fr(i,0,size-k+1){
    cout<<query(1,0,size-1,i,i+k-1)<<" ";
  }
  
  
}
