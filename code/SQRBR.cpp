#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    vector<int> bpos(2*n,0);

    fr(i,0,k){
      int c;cin>>c;c--;
      bpos[c] = 1;
    }

    vector<vector<int> > dp(2*n+1,vector<int> (2*n+1,0));
    dp[1][1] = 1;
    fr(i,2,2*n+1){
      fr(j,0,i+1){
	if(bpos[i-1]){
	  if(j==0)
	    dp[i][j] = 0;
	  else
	    dp[i][j] = dp[i-1][j-1];
	}
	else{
	  if(j==0)
	    dp[i][j] = dp[i-1][1];
	  else
	    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
	}
      }
    }
    cout<<dp[2*n][0]<<endl;
    
  }
}

    
    
    
