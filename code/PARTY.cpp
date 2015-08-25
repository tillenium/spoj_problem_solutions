#include<iostream>
#include<vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define fee first
#define fun second
#define mp(a,b) make_pair(a,b)
#define MAX(a,b) ((a.fun) > (b.fun) ? a : b)

typedef pair<int,int> ii;


int main(){
  int fee,n;
  while(cin>>fee>>n && fee && n){
  
    vector<int> fees(n);
    vector<int> fun(n);
    fr(i,0,n)
      cin>>fees[i]>>fun[i];
    vector<vector<int> > dp(n+1, vector<int> (fee+1,0));

    for(int i=1;i<n+1;i++){
      for(int j=1;j<fee+1;j++){
	if(j >= fees[i-1]) {
	  dp[i][j] = max(dp[i-1][j-fees[i-1]] + fun[i-1] , dp[i-1][j]);
	}
	else
	  dp[i][j] = dp[i-1][j];
      }
    }

    int best = dp[n][fee];
    int mfee = fee;
    for(int i=fee-1;i>=0;i--)
      if(dp[n][i] >= best){
	best = dp[n][i];
	mfee = i;
      }

    cout<<mfee<<" "<<best<<endl;
    
  }
}


