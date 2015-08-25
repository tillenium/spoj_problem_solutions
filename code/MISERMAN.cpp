#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))
int main(){
  int n,m;cin>>n>>m;
  vector<vector<int> > fare(n,vector<int> (m));

  fr(i,0,n)
    fr(j,0,m)
    cin>>fare[i][j];

  vector<vector<int> > dp(n+1,vector<int> (m+2,0));

  fr(i,0,n+1){
    dp[i][0] = dp[i][m+1] = 1000000000;
  }
  int ans = 1000000000;
  fr(i,1,n+1){
    fr(j,1,m+1){
      dp[i][j] = fare[i-1][j-1] + min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
      if(i==n && dp[i][j] < ans){
	ans = dp[i][j];
      }
    }
  }

  cout<<ans<<endl;
}

