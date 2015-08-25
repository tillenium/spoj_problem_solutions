#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define ff(i,a,b) for(int i=a;i>=b;i--)
#define abbs(a,b) ((a)>(b) ? a-b : b-a )

int main(){
  int n;cin>>n;
  vector<int> b(n);
  vector<int> h(n);
  fr(i,0,n){
    cin>>b[i];
    cin>>h[i];
  }

  vector<vector<int> > dp(n+1,vector<int> (1000,0));

  

  ff(i,n-1,0){
    fr(j,0,1000){
      dp[i][j] = max(dp[i+1][h[i]] + b[i] + ((i!=0) ? abbs(h[i],j) : 0), dp[i+1][b[i]] + h[i] + ((i!=0) ? abbs(b[i],j) : 0));
    }
  }
  cout<<dp[0][0]<<endl;
}

