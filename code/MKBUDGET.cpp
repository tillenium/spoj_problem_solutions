#include <iostream>
#include <vector>
using namespace std;

int main(){
  long long n,x,y,z;
  int count = 1;
  while(cin>>n && n){
    cin>>x>>y>>z;
    vector<long long> a(n);
    for(long long i=0;i<n;i++)
      cin>>a[i];

    vector<vector<long long> >dp(n+1, vector<long long> (31,0));

    for(int i=n-1;i>=0;i--){
      for(int j=30;j>=0;j--){
	if(a[i] > j){
	  dp[i][j] = dp[i+1][a[i]] + (a[i]-j)*x + a[i]*y;
	}
	else{
	  long long  min1 = -1;
	  for(int emp=a[i];emp<=j;emp++){
	    long long temp = dp[i+1][emp] + emp*y + (j-emp)*z;
	    if(min1==-1 || temp<min1)
	      min1 = temp;
	  }
	  dp[i][j] = min1;
	}
      }
    }

    cout<<"Case "<<count++<<", cost = $"<<dp[0][0]<<endl;
  }
}
	
    
