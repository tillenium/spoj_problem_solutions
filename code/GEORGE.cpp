#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define A second
#define cost first
#define mp(a,b) make_pair(a,b)

typedef pair<int,int> ii;

vector<vector<ii> > luka;
vector<int> george;
vector<vector<int> > timee;
int n,m,s,d,k,g;

int sssp(){
  priority_queue<ii> pq;
  pq.push(mp(-k,s));
  vector<int> dist(n,1);
  dist[s] = -k;
  while(!pq.empty()){
    ii u = pq.top(); pq.pop();
    cout<<u.A<<" "<<u.cost<<endl;
    if(dist[u.A]==u.cost){

      if(u.A==d)
	return dist[u.A];
      fr(i,0,luka[u.A].size()){
	ii v = luka[u.A][i];

	int t = u.cost*-1 + v.cost*-1;
	if(t<=timee[u.A][v.A])
	  t = timee[u.A][v.A] - t + 1;
	else if(t <= timee[v.A][u.A])
	  t = timee[u.A][v.A] - t + 1;
	else
	  t = 0;
	cout<<"dfgdf: "<<t<<endl;
	t *= -1;
	if(dist[v.A]==1 || dist[v.A] < dist[u.A] +  v.cost +t){
	  dist[v.A]=v.cost +t + dist[u.A];
	  pq.push(mp(dist[v.A],v.A));
	}
      }
    }
   
  }
   return -1;
}
int main(){
  cin>>n>>m>>s>>d>>k>>g;
  s--;d--;
  luka.resize(n);
  timee.resize(n,vector<int>(n,-1));  
  fr(i,0,g){
    int node;cin>>node;
    node--;
    george.push_back(node);
  }
  int gindex = 0;
  int temptime = 0;
  fr(i,0,m){
    int u,v,c;
    cin>>u>>v>>c;
    u--;v--;
    c *= -1;

    luka[u].push_back(mp(c,v));
    luka[v].push_back(mp(c,u));
  }
  
  fr(i,0,g-1){
    int x = george[i];
    int y = george[i+1];
    if(x>y){
      x = x+y;
      y = x;
      x = x - y;
    }
	  
    fr(j,0,luka[x].size()){
      ii v = luka[x][j];
      if(v.A==y){
	temptime += v.cost*-1;
	timee[x][y] = temptime;
      }
    }
  }
  cout<<-1*sssp()-k;
}
    
      

 
  


       
