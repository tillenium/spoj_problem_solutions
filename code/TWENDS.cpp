#include<iostream>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  int g = 1;
  while(cin>>n && n){
    vector<int> a(n);
    fr(i,0,n)
      cin>>a[i];

    vector<vector<int> > dp(n,vector<int> (n,0));
    int r[4] = {1,2,1,0};
    int c[4] = {-1,0,-1,-2};
    
    for(int i=n-2;i>=0;i--){
      fr(j,0,n){
	if(i < j){
	  int m = 0;
	  if(a[i+1] >= a[j] && i<n-2)
	    m = a[i] - a[i+1] + dp[i+2][j];
	  else
	    m = a[i] - a[j] + dp[i+1][j-1];
	  dp[i][j] = max(m,dp[i][j]);
	  
  	  if(a[i] < a[j-1] && j >1)
	    m = a[j] - a[j-1] + dp[i][j-2];
	  else
	    m = a[j] - a[i] + dp[i+1][j-1];
	  dp[i][j] = max(dp[i][j],m);
	}
      }
    }
    cout<<"In game "<<g++<<", the greedy strategy might lose by as many as "<<dp[0][n-1]<<" points."<<endl;
  }
}
  
	
   
