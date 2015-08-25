#include <iostream>
#include <vector>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a)>(b) ? b : a)
int main(){
  int n,e,t,m;
  cin>>n>>e>>t>>m;
  e--;
  vector<vector< int> > maze(n,vector<int> (n,1000000000));

  fr(i,0,m){
    int u,v,w;
    cin>>u>>v>>w;u--;v--;
    maze[u][v] = w;
  }

  fr(i,0,n)
    maze[i][i] = 0;

  
  fr(k,0,n){
    fr(i,0,n){
      fr(j,0,n){
	maze[i][j] = min(maze[i][j], maze[i][k]+maze[k][j]);
      }
    }
  }

  int count = 0;
  fr(i,0,n){
    if(maze[i][e] <= t)
      count++;
  }
  cout<<count;
}
