#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))
int main(){
  int t;cin>>t;
  while(t--){
    string s;
    cin>>s;
    vector<vector<int> > dp(s.size()+1,vector<int> (s.size()+1,0));

    for(int i=s.size()-1;i>=0;i--){
      fr(j,i+1,s.size()){
	if(s[i]==s[j])
	  dp[i][j] = dp[i+1][j-1];
	else
	  dp[i][j] = min(1+dp[i+1][j],1+dp[i][j-1]);
      }
    }

    cout<<dp[0][s.size()-1]<<endl;
  }
}
	  
