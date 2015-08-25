#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;

  vector<vector<long long> > dp(64, vector<long long> (10,0));
  fr(i,0,10)
      dp[0][i] = 1;

    fr(i,1,64){
      fr(j,0,10){
	fr(k,j,10){
	  dp[i][j] += dp[i-1][k];
	}
      }
    }
  while(t--){
    int a,b;
    cin>>a>>b;
    long long ans = 0;
    fr(i,0,10)
      ans += dp[b-1][i];

    cout<<a<<" "<<ans<<endl;
  }
}

      
