#include <iostream>
#include <vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  while(t--){
    int money,year;
    cin>>money>>year;
    int n;
    cin>>n;

    vector<int> amount(n);
    vector<int> interest(n);
    fr(i,0,n){
      cin>>amount[i]>>interest[i];
      amount[i] /=1000;
    }

    fr(k,0,year){
      int c = money/1000;

      vector<vector<int> > dp(n+1, vector<int> (c+1,0));

      fr(i,1,n+1){
	fr(j,1,c+1){
	  int another = 0;
	  if(j>=amount[i-1]){
	    another = max(dp[i][j-amount[i-1]] + interest[i-1] , dp[i-1][j-amount[i-1]] + interest[i-1]);
	  }

	  dp[i][j] = max(another, dp[i-1][j]);
	}
      }
      money += dp[n][c];
    }

    cout<<money<<endl;
  }
}

    

    
