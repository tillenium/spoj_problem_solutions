#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define stop first
#define cost second
#define mk(a,b) make_pair(a,b)
#define fr(i,a,b) for(int i=0;i<a;i++)

int n,v,e,x,y,c;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> graph;
vector<vector<int> >costVisited;

int bfs(int i, int j){
  queue<pair<int ,int> > q;
  vector<int> dist(n,-1);
  q.push(mk(0,0));
  long total = 0;
  while(!q.empty()){
    int u = q.front();q.pop();
    
  
  
}

int main(){
  cin>>n;
  
  while(n--){
    cin>>v>>e;
    graph.clear();
    graph.resize(v,vector<ii> (0));

    costVisited.clear();
    costVisited.resize(n, vector<int> (n,-1));
    fr(i,0,e){
      cin>>x>>y>>c;
      x--;y--;
      graph[x].push_back(mk(y,c));
    }
    
  }
}
    
    
