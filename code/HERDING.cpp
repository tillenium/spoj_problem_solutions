#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > visited;
vector<vector<int> >city;


int r[4] = {-1,0,1,0};
int c[4] = {0,1,0,-1};

int component = 1;
struct node{
  int i;
  int j;
};

int bfs(int i,int j){
  queue<node*> q;
  node *n = new node;
  n->i = i;
  n->j = j;
  q.push(n);
  visited[i][j] = component;
  bool otherComponent = false;
  while(!q.empty()){
    node *u = q.front();q.pop();
    //cout<<u->i<<" "<<u->j<<endl;
    node *v = new node;
    v->i = u->i + r[city[u->i][u->j]];
    v->j = u->j + c[city[u->i][u->j]];

    if(visited[v->i][v->j]==0){
      visited[v->i][v->j] = component;
      q.push(v);
    }
    else if(visited[v->i][v->j]!=component)
      return 0;
  }
  return 1;
}

int main(){
  int x,y;
  cin>>x>>y;
  char c;
  city.resize(x,vector<int> (y,0));
  visited.resize(x,vector<int> (y,0));
  for(int i=0;i<x;i++)
    for(int j=0;j<y;j++){
      cin>>c;
      if(c=='N')
	city[i][j] = 0;
      if(c=='E')
	city[i][j] = 1;
      if(c=='S')
	city[i][j] = 2;
      if(c=='W')
	city[i][j] = 3;
      
    }
  int catc = 0;
  int perCatch = 0;
  for(int i=0;i<x;i++)
    for(int j=0;j<y;j++){
      if(visited[i][j]==0){
	//cout<<i<<" "<<j<<endl;
	perCatch = bfs(i,j);
	//cout<<" "<<perCatch<<endl;
	catc += perCatch;
	component++;
      }
    }
  cout<<catc;
	

}
