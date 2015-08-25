#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b : a)

int main(){
  int t;cin>>t;
  while(t--){
    int w,h,n;
    cin>>w>>h>>n;
    vector<int> H(n);
    vector<int> W(n);
    fr(i,0,n)
      cin>>W[i]>>H[i];

    vector<vector<int> > dp(w+1, vector<int> (h+1,0));

    fr(i,1,w+1){
      fr(j,1,h+1){
	int m = i*j;
	fr(a,0,n){
	  if(i - W[a] < 0 || j - H[a] < 0)
	    continue;
	  m = min(m,dp[W[a]][j-H[a]] + dp[i-W[a]][j]);
	  m = min(m,dp[i-W[a]][H[a]] + dp[i][j-H[a]]);
	}
	dp[i][j] = m;
      }
    }

    cout<<dp[w][h]<<endl;
  }
}
