#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define cost first
#define A second
#define mp(a,b) make_pair(a,b)

typedef pair<int,int> ii;

vector<vector<ii> > roads;
int n,s,g;

map<string,int> names;

int sssp(){
  priority_queue<ii> pq;
  vector<int> dist(n,1);
  pq.push(ii(0,s));
  dist[s] = 0;
  while(!pq.empty()){
    ii u = pq.top();pq.pop();

    if(dist[u.A]==u.cost){

      if(u.A==g)
	return -1*dist[u.A];
      fr(i,0,roads[u.A].size()){
	ii v = roads[u.A][i];

	if(dist[v.A]==1 || dist[v.A] < dist[u.A] + v.cost){
	  dist[v.A] = dist[u.A] + v.cost;
	  pq.push(mp(dist[v.A],v.A));
	}
      }
    }
  }
  return -1;
}
    

int main(){
  int t;cin>>t;int p;string city;
  while(t--){
    cin>>n;
    roads.clear();
    roads.resize(n);
    names.clear();

    fr(i,0,n){
      cin>>city;
      names[city] = i;
      int p;cin>>p;
      fr(j,0,p){
	int nr,cost;cin>>nr>>cost;nr--;
	roads[i].push_back(mp(-1*cost,nr));
      }
    }

    int r;cin>>r;
    string a,b;
    fr(i,0,r){
      cin>>a>>b;
      s = names[a];
      g = names[b];
      cout<<sssp()<<endl;
    }
  }
}
