#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define A first
#define B second

int r[8] = {-1,-1,-1,0,0,1,1,1};
int c[8] = {-1,0,1,-1,1,-1,0,1};

typedef vector<int> vi;
typedef pair<int,int> ii;

int n,m;
vector<vi > graph;
vector<vi > visited;

int dfs(int x,int y){
  stack<ii> s;
  s.push(mp(x,y));
  int maxlength = 0;
  
  while(!s.empty()){
    ii u = s.top();s.pop();

    bool nextstate = false;
    fr(i,0,8){
      int vx = u.A + r[i];
      int vy = u.B + c[i];
      if(vx >=0 && vx < n && vy >= 0 && vy < m && !visited[vx][vy] && (graph[vx][vy] == graph[u.A][u.B] + 1)){
	s.push(mp(vx,vy));
	visited[vx][vy] = 1;
	nextstate = true;
      }
    }
    
    if(!nextstate && maxlength < graph[u.A][u.B])
      maxlength = graph[u.A][u.B];
  }
  return maxlength + 1;
}

int main(){
  int output = 1;
  while(cin>>n>>m && n && m){
    graph.clear();
    graph.resize(n,vector<int> (m));
    visited.clear();
    visited.resize(n,vector<int> (m,0));
    fr(i,0,n){
      fr(j,0,m){
	char x;cin>>x;
	graph[i][j] = x - 'A';
      }
    }

    int ans = 0;
    fr(i,0,n){
      fr(j,0,m){
	if(graph[i][j]==0){
	  int temp = dfs(i,j);
	  if(temp > ans)
	    ans = temp;
	}
      }
    }

    cout<<"Case "<<output++<<": "<<ans<<endl;
  }
}
