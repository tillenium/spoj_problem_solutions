#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

typedef vector<int> vi;
struct data{
  int sum;
  int pre;
  int suf;
  int ans;
};

data  defineData(int val){
  data n;
  n.sum =  val;
  n.pre = n.suf = n.ans = val;
  return n;
}

data combineData(data l, data r){
  data n;
  n.sum = l.sum + r.sum;
  n.pre = max ( l.pre, l.sum + r.pre);
  n.suf = max( r.suf, l.suf + r.sum);
  n.ans = max(max(max(max(max(l.ans,r.ans),l.suf + r.pre), n.suf), n.sum), n.pre);
  return n;
}

vi A;
vector<data> st(1000000);
int n;
int left(int p){ return p << 1;}
int right(int p){ return (p << 1) + 1;}

void build(int p,int L,int R){
  if(L==R){
    //cout<<L<<" "<<p<<endl;
    st[p] = defineData(A[L]);
    return;
  }

  build(left(p), L, (L+R)/2);
  build(right(p),(L+R)/2 + 1, R);
  st[p] = combineData(st[left(p)],st[right(p)]);
}

data rmq(int p,int L, int R, int i,int j){
  //  cout<<p<<" "<<L<<" "<<R<<" "<<i<<" "<<j<<endl;
  if(i==L && j==R)
    return st[p];

  int mid = (L+R) / 2;
  if(i > mid)
    return rmq(right(p),mid+1,R,i,j);
  if(j <= mid)
    return rmq(left(p),L,mid,i,j);

  data l = rmq(left(p),L,mid,i,mid);
  data r = rmq(right(p),mid+1,R,mid+1,j);

  return combineData(l,r);
}

int main(){
  cin>>n;
  st.clear();
  A.clear();A.resize(n);
  fr(i,0,n)
    cin>>A[i];

  build(1,0,n-1);
  int m;cin>>m;

  int x,y;
  fr(i,0,m){
    cin>>x>>y;x--;y--;
    cout<<rmq(1,0,n-1,x,y).ans<<endl;
  }
}

  
