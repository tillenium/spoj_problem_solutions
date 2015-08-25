#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  vector<vector<vector<int> > >dp(n,vector<vector<int> > (n, vector<int> (n+1,0)));

  fr(i,0,n)
    cin>>v[i];

  fr(i,0,n){
    fr(j,1,n+1){
      dp[i][i][j] = v[i]*j;
    }
  }

  for(int i=n-1;i>=0;i--){
    fr(j,i+1,n){
      for(int k=n;k>=1;k--){
	dp[i][j][k] = max(dp[i+1][j][k+1] + k*v[i], dp[i][j-1][k+1] + k*v[j]);
      }
    }
  }

  //fr(i,0,n+1)
  //cout<<dp[0][n-1][i]<<endl;
  cout<<dp[0][n-1][1];
}


	    
  
  
