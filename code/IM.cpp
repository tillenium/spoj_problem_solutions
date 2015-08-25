#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b : a )
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
vi p;
vvi cost;
int t,n,m,f;
vvi graph;
vector<int> flag;
void augment(int v,int minSum,int s){
  if(v==s){
    f = minSum;
    flag[s] = 1;
    return;
  }
  if(p[v]!=-1){
    augment(p[v],min(minSum,cost[p[v]][v]),s);
    cost[p[v]][v] -= f;
    cost[v][p[v]] += f;
    flag[v] = 1;
  }
}


int main(){
  cin>>t;
  int d,s;
  while(t--){
    cin>>n>>m;
    cost.clear();cost.resize(n,vi(n,0));
    graph.resize(n+1);
   
    fr(i,0,m){
      int u,v;
      cin>>u>>v;
      if(u>n || v>n || u<=0 || v <=0)
	continue;
      u--;v--;
      graph[u].push_back(v);
      cost[u][v] = 1;
      //graph[v].push_back(u);
      cost[v][u] = 1;
    }

    cost[0][n] = 1;cost[n][0] = 1;cost[2][n] = 1;cost[n][2] = 1;
    //adding new node to naboo and coruscant
    //graph[0].push_back(n);
    //graph[n].push_back(0);
    //graph[2].push_back(n);
    //graph[n].push_back(2);

    //reducing graph so that changing nodes into edges and edges into nodes
    //for vertex disjoint graph
    
    
    vector<vector<int> > newg(2*(n+1),vector<int> (2*(n+1),0));

    fr(i,0,n+1){
      newg[2][i*2] = (cost[1][i]==0 ? cost[i][1] : cost[1][i]);
    }
    newg[1][2n] = 1;
    newg[5][2n] = 1;

    fr(i,0,n+1){
      fr(j,0,n+1){
	
      //Newg*2][2] = cost[1][i];
      
    

    

    
    bool ans = true;
    while(1){
	f= 0;
	s = 0;
	d = 1;
	vi dist(n,-1);
	p.clear(); p.resize(n,-1);
	flag.clear();
	flag.resize(n,0);
	stack<int> q;q.push(s);
	dist[s] = 0;
	while(!q.empty()){
	  int u = q.top();q.pop();

	  if(u==d)
	    break;
	  fr(i,0,n){
	    int v = i;
	    if(cost[u][v]>0 && dist[v]==-1){
	      dist[v] = dist[u] + 1;q.push(v);p[v] = u;
	    }
	  }
	}
	augment(d,1000000000,s);
	
	if(f==0){
	  ans = false;
	  break;
	}
	q = stack<int>();
	f= 0;
	s = 1;
	d = 2;
	dist.clear();
	dist.resize(n,-1);
	//p.clear(); p.resize(n,-1);
	q.push(s);
	dist[s] = 0;
	while(!q.empty()){
	  int u = q.top();q.pop();
	
	  if(u==d)
	    break;
	  
	  fr(i,0,n){
	    int v = i;
	
	    if(cost[u][v]>0 && flag[v]==0  && dist[v]==-1){
	
	      dist[v] = dist[u] + 1;q.push(v);p[v] = u;
	    }
	  }
	}
	augment(d,1000000000,s);

	if(f!=0){
	  ans = true;
	  break;
	}
    }

    cout<<(ans ? "YES" : "NO")<<endl;
  }
}
 

