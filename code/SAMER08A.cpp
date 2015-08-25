#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define A second
#define cost first
#define mp(a,b) make_pair(a,b)

typedef pair<int,int> ii;


vector<int> froms;
vector<int> fromd;
int n,m,s,d;

int sssp(vector<vector<int> > g, int start,vector<int> &f,bool ret){
  priority_queue<ii> pq;
  f.clear();
  f.resize(n,1);
  pq.push(mp(0,start));
  f[start] = 0;
  int shortpath = -1;
  while(!pq.empty()){
    ii u = pq.top();pq.pop();

    if(u.cost==f[u.A]){
      if(ret && u.A==d)
	return u.cost*-1;
      fr(i,0,n){

	if(g[u.A][i]!=0){
	  ii v = mp(g[u.A][i],i);

	  if(f[v.A]==1 || f[v.A] < u.cost + v.cost){
	    f[v.A]  = u.cost + v.cost;
	    v.cost = f[v.A];
	    pq.push(v);
	  }
	}
      }
    }
  }
  return -1;
}

int main(){

  while(cin>>n>>m && n && m){
    cin>>s>>d;

    vector< vector<int> > g1(n,vector<int> (n,0));
    vector<vector<int> > g2(n,vector<int> (n,0));
 
    fr(i,0,m){
      int u,v,w;
      cin>>u>>v>>w;

      g1[u][v] = -w;
      g2[v][u] = -w;
    }
    
    sssp(g1,s,froms,false);
    sssp(g2,d,fromd,false);

    int spath = froms[d];

    fr(i,0,n){
      fr(j,0,n){
	if(i!=j && g1[i][j]!=0){
	  if(froms[i]!= 1  &&  fromd[j]!=1){
	    if(froms[i] + g1[i][j] + fromd[j] == spath)
	      g1[i][j] = 0;
	  }
	}
      }
    }

    cout<<sssp(g1,s,froms,true)<<endl;

  }
}
