#include<iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int n,k;


int main(){
  int t;cin>>t;
  int ind;
  while(t--){
    cin>>ind>>n>>k;
    
    vector<vector< vector<int> > > mem(n+1,vector<vector<int> > (n+1,vector<int> (2,0)));

    mem[0][k][0] = 1;
    mem[0][k][1] = 1;
    
    fr(i,1,n+1){
      fr(j,0,k+1){
	fr(p,0,2){

	  if(p==1){
	    mem[i][j][p] += mem[i-1][j+1][1];
	  }
	  else
	    mem[i][j][p] += mem[i-1][j][1];
	  mem[i][j][p] += mem[i-1][j][0];
	}
      }
    }
    cout<<ind<<" "<<mem[n][0][0]<<endl;
  }
}
