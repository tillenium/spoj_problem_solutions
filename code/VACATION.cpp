#include <iostream>
#include <vector>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b: a)
int main(){
  int n,m,k1,q;
  cin>>n>>m>>k1>>q;
  vector<vector<int> > path(n,vector<int> (n,-1));
  vector<vector<int> > number(n,vector<int> (n,0));

  fr(i,0,n)
    path[i][i]=0;
  
  fr(i,0,m){
    int u,v,d;
    cin>>u>>v>>d;u--;v--;
    path[u][v] = d;
  }

  fr(k,0,n){
    fr(i,0,n){
      fr(j,0,n){
	if(path[i][k] != -1 && path[k][j]!= -1){
	  if(path[i][j]==-1)
	    path[i][j] = path[i][k] + path[k][j];
	  else
	    path[i][j] = min(path[i][j],path[i][k] + path[k][j]);
	}
      }
    }
  }

  long num=0,ans=0;

  fr(i,0,q){
     int u,v;
    cin>>u>>v; u--;v--;
    int nn=0,mm=-1;
    fr(k,0,k1){
      if((u<k1 && v<k1 && v==k)){
	if(u==v)
	  mm = path[u][v];
      }
      else if(path[u][k]!=-1 && path[k][v]!=-1){
	nn++;

	if(mm==-1)
	  mm = path[u][k] + path[k][v];
	else
	  mm = min(mm,path[u][k]+path[k][v]);
      }	
    }
    num += nn;
    if(mm!=-1)
      ans += mm;
  }
  cout<<num<<endl<<ans<<endl;
}
    
    
