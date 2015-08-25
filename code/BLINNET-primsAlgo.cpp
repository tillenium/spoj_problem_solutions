#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define cost first
#define A second


int n,s;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<vector<ii> > edges;
vector<int> taken;
int mincost;
priority_queue<ii> pq;

void process(int v){
  taken[v] = 1;
  fr(i,0,edges[v].size()){
    ii vtx = edges[v][i];
    if(!taken[vtx.A])
      pq.push(vtx);
  }
}
void mst(){
  
  process(0);
  while(!pq.empty()){
    ii front = pq.top();pq.pop();
    if(!taken[front.A]){
      //cout<<front.cost<<endl;
      mincost += front.cost;
      process(front.A);
    }
  }
}

int main(){
  cin>>s;
  while(s--){
    cin>>n;
    mincost = 0;
    edges.clear();
    taken.clear();
    edges.resize(n);
    taken.resize(n,0);
    fr(i,0,n){
      string city;cin>>city;
      int p; cin>>p;
      int next,cost;
      fr(j,0,p){
	cin>>next>>cost;
	next--;
	edges[i].push_back(mp(-cost,next));
      }
    }
    mst();
    cout<<mincost*-1<<endl;
  }
}
