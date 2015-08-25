#include <iostream>
#include <vector>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define back(i) ((i)==0 ? n-1 : i-1)
#define fwd(i) ((i+1)%n)

int main(){
  int n,k;
  int a,b;
  while(cin>>n>>k && n!=-1 && k!= -1){
    cin>>a>>b;
    a--;b--;
    vector<vector<long long> > dp(k+1,vector<long long> (n,0));

    dp[0][a] = 1;

    fr(i,1,k+1){
      fr(j,0,n){
	dp[i][j] = dp[i-1][back(j)] + dp[i-1][fwd(j)];
      }
    }

    cout<<dp[k][b]<<endl;
  }
}
