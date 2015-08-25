#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define cost first
#define A second
#define mp(b,c) make_pair(b,c)

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n,m,k,s,t;

bool operator <( ii a, ii b ) {
  return a.cost < b.cost;
}

vector<int> froms;
vector<int> fromt;
void sssp(vector<vector<ii> >& net,vector<int>dist,int s){
  priority_queue<ii> pq;
  pq.push(mp(0,s));
  //vector<int> dist(n,1);
  dist[s] = 0;

  while(!pq.empty()){
    ii v = pq.top();pq.pop();
    if(v.cost==dist[v.A]){
      fr(i,0,net[v.A].size()){
	ii nv = net[v.A][i];
	if(dist[nv.A]==1 || dist[nv.A] < dist[v.A]+nv.cost){
	    dist[nv.A] = dist[v.A] + nv.cost;
	    pq.push(mp(dist[nv.A],nv.A));
	}
      }
    }
  }

}

int main(){
  int t1;cin>>t1;
  while(t1--){
    cin>>n>>m>>k>>s>>t;
    vector<vector<ii> > net1(n);
    vector<vector<ii> > net2(n);
    froms.clear();fromt.clear();
    froms.resize(n,1);fromt.resize(n,1);



    fr(i,0,m){
      ii temp;
      int u;
      cin>>u>>temp.A>>temp.cost;
      u--;temp.A--;
      temp.cost *= -1;
      net1[u].push_back(temp);
      net2[temp.A].push_back(mp(temp.cost,u));
    }
    s--;t--;
    
    sssp(net1,froms,s);
    sssp(net2,fromt,t);
    int ans = max(froms[t],fromt[s]);
    
    fr(i,0,k){
      int v,w;
      int u;
      cin>>u>>v>>w;
      u--;v--;
      w *= -1;
      if(froms[u] != 1 && fromt[v]!=1){
	int mm = froms[u] + w + fromt[v];
	if(ans == 1 || ans < mm)
	  ans = mm;
      }
      int temp = u;
      u = v;
      v  = temp;
      if(froms[u] != 1 && fromt[v]!=1){
	int mm = froms[u] + w + fromt[v];
	if(ans == 1 || ans < mm)
	  ans =mm;
      }
    }
      cout<<ans*-1<<endl;
    }
    }
    
      
    



