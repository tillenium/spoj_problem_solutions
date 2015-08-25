#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second
#define mp(a,b) make_pair(a,b)

typedef pair<int,int> ii;
typedef vector<int> vi;
vector<vi> graph;
vector<ii> ride;
int n,C;
vi weight;
vi visited;
ii bfs(int start){
  queue<int> q;q.push(start);
  ii component = mp(0,0);
  visited[start] = 1;
  while(!q.empty()){
    int u = q.front();q.pop();
    component.A += 1;
    component.B += weight[u];

    fr(i,0,graph[u].size()){
      int v = graph[u][i];
      if(!visited[v]){
	q.push(v);
	visited[v] = 1;
      }
    }
  }
  return component;
}
void bfsTraversal(){
  visited.clear();visited.resize(n,0);
  fr(i,0,n){
    if(!visited[i]){
      ii comp = bfs(i);
      ride.push_back(comp);
    }
  }
}

int main(){
  while(cin>>n>>C && n && C){
    graph.clear();weight.clear();ride.clear();
    graph.resize(n,vector<int> (0));
    weight.resize(n,0);
    ride.resize(0);
    fr(i,0,n)
      cin>>weight[i];

    fr(i,0,n){
      int m;cin>>m;
      int v;
      fr(j,0,m){
	cin>>v;v--;
	graph[i].push_back(v);
	graph[v].push_back(i);
      }
    }

    bfsTraversal();

    //knapsack for the problem:
    int x = ride.size();
    vector<vi> dp(x+1, vi(C+1,0));

    fr(i,1,x+1){
      fr(j,1,C+1){
	int another = 0;
	if(j>=ride[i-1].B)
	  another =  ride[i-1].A + dp[i-1][j-ride[i-1].B];
	dp[i][j] = max(another, dp[i-1][j]);
      }
    }

    cout<<dp[x][C]<<endl;
    
   
    
  }
}
