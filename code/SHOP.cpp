#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

#define cost first
#define x second.first
#define y second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

typedef pair<int,int> ii;
typedef pair<int ,ii > iii;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph;
vvi visited;

int n,m;

int r[4] = {-1,0,0,1};
int c[4] = {0,-1,1,0};

int search(ii s, ii d){
  priority_queue<iii> pq;
  pq.push(mp(0,s.first,s.second));

  visited[s.first][s.second] = 1;
  while(!pq.empty()){
    iii u = pq.top();pq.pop();

    if(u.x == d.first && u.y == d.second)
      return -1*u.cost;

    fr(i,0,4){
      int vx = u.x + r[i];
      int vy = u.y + c[i];

      if(vx >=0 && vx < n && vy>=0 && vy < m && !visited[vx][vy] && graph[vx][vy] != 1){
	visited[vx][vy]  = 1;
	pq.push(mp(u.cost + graph[vx][vy],vx,vy)); 
      }
    }

  }
  return -1;
}
  


int main(){
  while(cin>>m>>n && n && m){
    graph.clear();visited.clear();
    graph.resize(n,vector<int> (m));
    visited.resize(n,vector<int> (m,0));

    ii s,d;
    fr(i,0,n){
      fr(j,0,m){
	char c;cin>>c;
	if(c=='S'){
	  s = make_pair(i,j);
	  graph[i][j] = 0;
	}
	else if(c=='D'){
	  d = make_pair(i,j);
	  graph[i][j] = 0;
	}
	else if(c=='X'){
	  graph[i][j] = 1;
	}
	else
	  graph[i][j] = '0' - c;
      }
    }

    cout<<search(s,d)<<endl;
  }
}
	  
