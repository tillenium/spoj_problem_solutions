#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b : a)
int main(){
  int t,x,y,n;
  cin>>t;
  while(t--){
    cin>>x>>y>>n;
    vector<int> X(n);
    vector<int> Y(n);
    vector<int> W(n);

    fr(i,0,n)
      cin>>X[i]>>Y[i]>>W[i];

    vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (x+1,vector<int> (y+1,1000000000)));
    dp[0][0][0] = 0;

    fr(i,1,n+1)
      dp[i][0][0] = 0;
    
    
    fr(i,1,n+1){
      fr(j,0,x+1){
	fr(k,0,y+1){
	  if(j-X[i-1] >=0 && k-Y[i-1]>=0)
	    dp[i][j][k] = min(dp[i-1][j-X[i-1]][k-Y[i-1]] + W[i-1], dp[i-1][j][k]);
	  else if(k-Y[i-1]>=0){
	    dp[i][j][k]= min(dp[i-1][0][k-Y[i-1]] + W[i-1], dp[i-1][j][k]);
	  }
	  else if(j-X[i-1] >=0)
	    dp[i][j][k]= min(dp[i-1][j-X[i-1]][0] + W[i-1], dp[i-1][j][k]);
	  else
	    dp[i][j][k] = min(dp[i][0][0] + W[i-1], dp[i-1][j][k]);
	}
      }
    }


    cout<<dp[n][x][y]<<endl;
  }
}
	    
