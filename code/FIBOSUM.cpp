#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

struct matrix{
  long long mat[2][2];
};

matrix matMul(matrix a, matrix b){
  matrix ans;
  fr(i,0,2){
    fr(j,0,2){
      ans.mat[i][j]=0;
      fr(k,0,2){
	ans.mat[i][j] =(ans.mat[i][j] +  (a.mat[i][k]*b.mat[k][j])%1000000007)%1000000007;
      }
    }
  }
  return ans;
}

matrix matPow(matrix base, int p){
  matrix ans;
  fr(i,0,2)
    fr(j,0,2)
    ans.mat[i][j] = (i==j);

  while(p){
    if(p&1)
      ans = matMul(ans,base);
    base = matMul(base,base);
    p =p>>1;
  }
  return ans;
}

int main(){
  matrix base;
  base.mat[0][0]= base.mat[0][1]= base.mat[1][0] = 1;
  base.mat[1][1] = 0;

  int t;
  cin>>t;
  while(t--){
    int n, m;cin>>n>>m;
    int a = (matPow(base,m+2).mat[0][1] - matPow(base,n+1).mat[0][1])%1000000007;
    if(a<0)
      a = (a + 1000000007)%1000000007;
    cout<<a<<endl;
  }
}
