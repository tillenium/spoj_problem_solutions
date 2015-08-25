#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define cost first
#define A second

typedef pair<int,int> ii;
int n,k;
vector<vector<ii> > floor;

int sssp(){
  priority_queue<ii> pq;
  pq.push(mp(0,0));
  vector<int> dist(n,1);
  dist[0] = 0;
  while(!pq.empty()){
    ii v = pq.top();pq.pop();
    if(v.cost==dist[v.A]){

      if(v.A==n-1)
	return dist[n-1];
      fr(i,0,floor[v.A].size()){
	ii u = floor[v.A][i];
	int floor = v.A - u.A < 0 ? u.A - v.A : v.A - u.A;
	int cost = 0;
	int reached = (-1*v.cost/5)%(2*floor);
	int high = v.A > u.A ? v.A : u.A;
	int extraCost = 0;
	if(u.A > v.A){
	  extraCost = reached==0 ? 0 : (2*floor - reached)*5;
	}
	else{
	  if(reached<=floor){
	    extraCost = (floor-reached)*5;
	  }
	  else{
	    extraCost = (2*floor - reached)*5;
	  }
	}
			     
	cost += -1*extraCost + v.cost + -1*floor*5;

	if(dist[u.A]==1 || dist[u.A] < cost){
	  dist[u.A] = cost;
	  u.cost = cost;
	  pq.push(u);
	}
      }
    }
  }
  return -1;
}

int main(){
  cin>>n>>k;
  floor.resize(n);

  fr(i,0,k){
    int u,v,w;
    cin>>u>>v;
    u--;v--;
    //w = u-v > 0 ? v-u : u-v;
    floor[u].push_back(mp(0,v));
    floor[v].push_back(mp(0,u));
  }

  cout<<-1*sssp()<<endl;

}
