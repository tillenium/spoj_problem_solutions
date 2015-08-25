#include <iostream>
#include <vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  fr(c,1,t+1){
    int n,r;
    cin>>n;
    vector<vector<int> > path(n,vector<int> (n,0));
    int cc;
    fr(i,0,n)
      fr(j,0,n){
      cin>>cc;
      if(cc!=0)
	path[i][j] = cc;
    }

    fr(k,0,n)
      fr(i,0,n)
      fr(j,0,n)
      path[i][j] = min(path[i][j],path[i][k]+path[k][j]);

    cin>>r;
    int ans = 0;

    fr(i,0,r){
      int u,v;cin>>u>>v;u--;v--;
      ans += path[u][v];
    }

    cout<<"Case #"<<c<<": "<<ans<<endl;
  }
}
  
      

    

    
