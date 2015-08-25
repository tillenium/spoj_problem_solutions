#include<iostream>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))
int main(){
  int n;
  int count = 1;
  while(cin>>n && n){
    vector<vector<int> > g(n,vector<int> (3));
    fr(i,0,n){
      fr(j,0,3){
	cin>>g[i][j];
      }
    }

    vector<vector<int> > dp(n,vector<int> (3,0));

    dp[n-1][2] = 1000000000;
    dp[n-1][1] = g[n-1][1];
    dp[n-1][0] = g[n-1][0] + dp[n-1][1];

    for(int i=n-2;i>=0;i--){
      for(int j=2;j>=0;j--){
	if(j==2){
	  dp[i][j] = min(dp[i+1][j],dp[i+1][j-1]) + g[i][j];
	}
	if(j==1){
	  dp[i][j] = min(dp[i][j+1],min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]))) + g[i][j];
	}
	if(j==0){
	  dp[i][j] = min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1])) + g[i][j];
	}
      }
    }
    cout<<count++<<". "<<dp[0][1]<<endl;
  }
}
