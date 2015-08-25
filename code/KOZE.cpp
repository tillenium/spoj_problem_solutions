#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define A first
#define B second
typedef pair<int,int> ii;

vector<vector<char> > g;
vector<vector<int> >visited;
int m,n;

int s=0,w=0;
int r[4] = {-1, 0, 0, 1};
int c[4] = {0, -1, 1, 0}; 

ii bfs(int x,int y){
  queue<ii> q;
  q.push(mp(x,y));
  visited[x][y] = 1;
  ii rem;
  rem.A = 0;
  rem.B = 0;
  bool breakage = false;
  while(!q.empty()){
    ii v = q.front();q.pop();
    if(v.A==0 || v.A==m-1 || v.B==0 || v.B==n-1)
      breakage = true;
    if(g[v.A][v.B]=='k')
      rem.A++;
    if(g[v.A][v.B]=='v')
      rem.B++;
    fr(i,0,4)
      if(v.A+r[i]>=0 && v.A+r[i]<m && v.B+c[i]>=0 && v.B+c[i]<n){
	if(g[v.A+r[i]][v.B+c[i]]!='#' && !visited[v.A+r[i]][v.B+c[i]]){
	    visited[v.A+r[i]][v.B+c[i]] = 1;
	    q.push(mp(v.A+r[i],v.B+c[i]));
	  }
      }
  }
  if(breakage)
    return rem;
  if(rem.A>rem.B)
    rem.B = 0;
  else
    rem.A = 0;
  return rem;
}

void count(){
  ii count;
  ii ret;
  count.A = 0;
  count.B = 0;
  fr(i,0,m)
    fr(j,0,n)
    if(!visited[i][j] && g[i][j]!='#'){
      ret = bfs(i,j);
      count.A += ret.A;
      count.B += ret.B;
    }

  cout<<count.A<<" "<<count.B;
}

int main(){
  cin>>m>>n;
  g.resize(m,vector<char> (n));
  visited.resize(m,vector<int>(n,0));
  fr(i,0,m)
    fr(j,0,n)
    cin>>g[i][j];
  count();
}
