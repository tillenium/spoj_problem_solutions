#include <iostream>
#include <vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  int n,c;
  
  while(t--){
    cin>>c>>n;
    vector<int> weight(n);
    vector<int> value(n);

    fr(i,0,n){
      cin>>weight[i]>>value[i];
    }

    vector<vector<int> > dp(n+1, vector<int> (c+1,0));

    fr(i,1,n+1){
      fr(j,1,c+1){
	int another = 0;
	if(j>= weight[i-1])
	  another = dp[i-1][j-weight[i-1]] + value[i-1];
	dp[i][j] = max(another, dp[i-1][j]);
      }
    }

    cout<<"Hey stupid robber, you can get "<<dp[n][c]<<"."<<endl;
  }
}
    
