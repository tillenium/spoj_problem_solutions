#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<vector<int> > d(n,vector<int> (n));

    fr(i,0,n)
      fr(j,0,n)
      cin>>d[i][j];

    int d1,d2;
    bool neighbour = true;
    fr(i,0,n){
      fr(j,i+1,n){
	d1 = d[i][j];
	neighbour = true;
	fr(k,0,n){
	  if(k==i || k==j)
	    continue;
	  d2 = d[i][k] + d[k][j];
	  if(d1==d2){
	    neighbour = false;
	    break;
	  }
	}
	if(neighbour)
	  cout<<i+1<<" "<<j+1<<endl;
      }
    }
    cout<<endl;
  }
}
	  
