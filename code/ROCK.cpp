#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<int> a(n+1);
    a[0] = 0;
    fr(i,1,n+1){
      char c;cin>>c;
      a[i] = a[i-1] + (c-'0');
    }

    vector<vector<int> > dp(n+1, vector<int> (n+1,0));

    fr(i,1,n+1)
      dp[i][i] = a[i] - a[i-1];

    for(int i=n;i>0;i--){
      fr(j,i,n+1){
	if(i!=j){
	  if(a[j] - a[i-1] > (j-i+1)/2)
	    dp[i][j] = j - i + 1;
	  else{
	    int m = 0;
	    fr(k,1,j){
	      int temp = dp[i][k] + dp[k+1][j];
	      if(temp > m)
		m = temp;
	    }
	    dp[i][j] = m;
	  }
	}
      }
    }

    cout<<dp[1][n]<<endl;
    
  }
}
