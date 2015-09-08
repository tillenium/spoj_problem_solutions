#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t,n;cin>>t;
  vector<int> dp(1000001,0);
  fr(i,1,1000001){
    dp[i] = (dp[i-1] + i*2 + i-1)%1000007;
  }

  while(t--){
    cin>>n;
    cout<<dp[n]<<endl;
  }
}
  
