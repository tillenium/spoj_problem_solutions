#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b : a )
vector<vector<int> > cost;
vector<vector<int> > g;
vector<int> p;
int n,mf,f,s,t;

int index(char s){
  if(s>='a')
    return 26 + (s-'a');
  return s-'A';
}

void augment(int v,int minEdge){
  if(v==s){
    f = minEdge;return;
  }
  if(p[v]!=-1){
    augment(p[v],min(minEdge,cost[p[v]][v]));
    cost[p[v]][v] -= f;
    cost[v][p[v]] += f;
  }
}

int main(){
  cin>>n;
  cost.resize(52, vector<int> (52,0));
  
  g.resize(n);
  fr(i,0,n){
    char u,v;int c;
    cin>>u>>v>>c;
    //g[index(u)].push_back(index(v));
    //g[index(v)].push_back(index(u));
    //if(cost[index(u)][index(v)]!=0)
    cost[index(u)][index(v)] += c;
    //cost[index(v)][index(u)] += c;

  }
  s = index('A');
  t = index('Z');
  mf = 0;
  while(1){
    f=0;
    vector<int> dist(52,-1);
    dist[s] = 0;
    queue<int> q;q.push(s);
    p.clear();p.resize(52,-1);
    while(!q.empty()){
      int u = q.front();q.pop();
      if(u==t)
	break;

      fr(i,0,52){
	int v = i;
	if(cost[u][v] > 0 && dist[v]== -1){
	  dist[v] = dist[u] + 1;q.push(v);p[v] = u;
	}
      }
    }

    augment(t,1000000000);
    if(f==0)
      break;
    mf += f;
    //cout<<mf;
  }
  cout<<mf;
}

  
    
