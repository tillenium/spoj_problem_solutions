#include<iostream>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b : a)

int main(){
  int n;
  while(cin>>n){
    vector<long long> color(n+1);
    color[0] = 0;
    fr(i,0,n){
      cin>>color[i+1];
      color[i+1] += color[i];
    }

    vector<vector<long long> > dp(n+1,vector<long long> (n+1,1000000000));

    fr(i,0,n+1)
      dp[i][i] = 0;
    
    for(int i=n;i>=1;i--){
      for(int j=i+1;j<=n;j++){
	int m = 1000000000;
	fr(k,i,j){
	  m = min(m, dp[i][k] + dp[k+1][j] + ((color[k]-color[i-1])%100)*((color[j]-color[k])%100));
	  
	}
	dp[i][j] = m;
      }
    }

    cout<<dp[1][n]<<endl;
  }
}
