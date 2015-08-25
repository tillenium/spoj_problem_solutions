#include <iostream>
#include <vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t,n;cin>>t;
  fr(c,1,t+1){
    cin>>n; vector<int> ar(n);
    fr(i,0,n)
      cin>>ar[i];

    vector<vector<long long> > dp(n+1,vector<long long> (2,0));

    fr(i,1,n+1){
      fr(j,0,2){
	if(j==1)
	  dp[i][j] = max(dp[i-1][0] + ar[i-1], dp[i-1][1]);
	else
	  dp[i][j] = dp[i-1][1];
      }
    }

    cout<<"Case "<<c<<": "<<dp[n][1]<<endl;
  }
}
