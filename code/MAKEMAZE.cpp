#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define RESIZE(m,n) resize(m,vector<int> (n,0))
#define mp(a,b) make_pair(a,b)
#define A first
#define B second
typedef pair<int,int> ii;
vector<vector<char> > maze;
vector<vector<int> > visited;
vector<ii> enter_ways;
int m,n;

int r[4] = {-1,0,0,1};
int c[4] = {0,-1,1,0};

bool bfs(){
  queue<ii> q;
  q.push(enter_ways[0]);
  visited[enter_ways[0].A][enter_ways[0].B] = 1;
  int x,y;
  while(!q.empty()){
    ii v = q.front();q.pop();
    if(v.A==enter_ways[1].A && v.B==enter_ways[1].B)
      return true;
    
    fr(i,0,4){
      x = v.A+r[i];
      y = v.B+c[i];

      if(x>=0 && x<m && y>=0 && y<n){
	if(!visited[x][y] && maze[x][y]=='.'){
	  visited[x][y] = 1;
	  q.push(mp(x,y));
	}
	  
      }
    }
  }
  return false;
}


int main(){
  int t;cin>>t;
  while(t--){
    cin>>m>>n;
    
    maze.clear();
    maze.resize(m,vector<char> (n,'0'));
    visited.clear();
    visited.RESIZE(m,n);
    enter_ways.clear();
    enter_ways.resize(0);
    fr(i,0,m)
      fr(j,0,n){
      cin>>maze[i][j];
      if(maze[i][j]=='.' && (i==0 || i==m-1 || j==0 || j==n-1)){
	enter_ways.push_back(mp(i,j));
      }
    }
    //cout<<enter_ways.size()<<endl;
    if(enter_ways.size()!=2)
      cout<<"invalid"<<endl;   
    else{
      if(bfs())
	cout<<"valid"<<endl;
      else
	cout<<"invalid"<<endl;
    }
  }
}
