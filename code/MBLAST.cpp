#include <iostream>
#include <vector>

using namespace std;

#define min(a,b) ((a) > (b) ? b : a)
#define abss(a,b) ((a) > (b) ? a-b : b-a)
#define diff(a,b) (int) (abss(a,b))
//vector<vector<vector<int> > > mem;
string a,b;
int k;

int main(){
  cin>>a>>b>>k;
  //mem.resize(a.size(), vector<vector<int> > (b.size(), vector<int> (k*(max(a.size(),b.size())+2),-1)));
  int n =a.size();
  int m = b.size();
  vector<vector<int> > dp(n+1,vector<int> (m+1,0));
  for(int j=1;j<=m;j++)
    dp[0][j] = j*k;

  for(int i=1;i<=n;i++){
    dp[i][0] = i * k;
    for(int j=1;j<=m;j++){
      dp[i][j] = min(dp[i-1][j-1] + diff(a[i-1],b[j-1]), min(dp[i-1][j] + k, dp[i][j-1]+k));
    }
  }
  
  
  cout<<dp[n][m]<<endl;
}
