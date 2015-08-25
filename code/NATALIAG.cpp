#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second
#define mp(a,b) make_pair(a,b)

typedef pair<int,int> ii;

vector<vector<char> > maze;
vector<vector<int> > cost;

int m,n;
ii start;
ii goal;

int r[4] = {-1,0,0,1};
int c[4] = {0,-1,1,0};

int bfs(){
  queue<ii> q;
  q.push(start);
  cost[start.A][start.B] = 0;

  while(!q.empty()){
    ii v= q.front();q.pop();

    if(v.A==goal.A && v.B==goal.B)
      return cost[v.A][v.B];
    fr(i,0,4){
      int x = v.A + r[i];
      int y = v.B + c[i];

      if(x>=0 && x<m && y>=0 && y<n){
	if((maze[x][y]!='*')  && (cost[x][y]==-1 || cost[x][y]>cost[v.A][v.B]+1)){
	  cost[x][y] = cost[v.A][v.B] + 1;
	  q.push(mp(x,y));
	}
      }
    }
  }
  return -1;
}

int main(){
  int t;cin>>t;
  while(t--){
    cin>>m>>n;

    maze.clear();cost.clear();
    maze.resize(m,vector<char> (n));
    cost.resize(n,vector<int> (n,-1));

    fr(i,0,m)
      fr(j,0,n){
      cin>>maze[i][j];
      if(maze[i][j]=='$'){
	start.A=i;
	start.B=j;
      }
      if(maze[i][j]=='#'){
	goal.A=i;goal.B=j;
      }
    }
    cout<<bfs()<<endl;
  }
}
