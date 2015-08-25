#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
int main(){
  int t;cin>>t;
  int n,c,a,b,components;
  while(t--){
    cin>>n>>c;
    vector<vi> adj(n,vi(0));
    for(int i=0;i<c;i++){
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    components = 0;
    vector<int> visited(n,0);

    for(int v=0;v<n;v++){
      if(!visited[v]){
	queue<int> q;
	q.push(v);
	visited[0] = 1;
	while(!q.empty()){
	  a = q.front();q.pop();
	  for(int i=0;i<adj[a].size();i++){
	    b = adj[a][i];
	    if(!visited[b]){
	      visited[b] = 1;
	      q.push(b);
	    }
	  }
	}
	components++;
      }
    }
    cout<<components<<endl;
  }
}
