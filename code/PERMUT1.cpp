#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;

    vector<vector<int> > dp(n+1,vector<int> (k+1,0));

    fr(i,1,n+1)
      dp[i][k] = 1;

    for(int i=n-1;i>=1;i--){
      fr(j,0,k){

	int s = 0;
	fr(x,0,i+1){
	  int inv = j + (i-x);
	  if(inv <= k)
	    s += dp[i+1][inv];
	}
	dp[i][j] = s;
      }
    }

    cout<<dp[1][0]<<endl;
  }
}
