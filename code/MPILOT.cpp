#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))
int main(){
  int n;
  cin>>n;
  vector<long> c(n);
  vector<long> a(n);

  fr(i,0,n){
    cin>>c[i]>>a[i];
  }

  vector<vector<long> > dp(n+1,vector<long> (n+1,0));

  fr(i,1,n+1)
    dp[0][i] = 100001;

  fr(i,1,n+1){
    fr(j,0,n){
      if(j==0)
	dp[i][j] = dp[i-1][j+1] + c[i-1];
      else
	dp[i][j] = min(dp[i-1][j+1] + c[i-1],dp[i-1][j-1] + a[i-1]);
    }
  }

  
  cout<<dp[n][0];
}
