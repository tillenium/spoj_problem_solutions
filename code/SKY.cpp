#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second.first
#define C second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

typedef pair<int ,int > ii;
typedef pair<int,ii> iii;
struct Comparator{
  bool operator() (const iii x, const iii y){
    return x.C>y.C;
  }
};

vector<vector<int> > grid;
vector<vector<int> > cost;
int n,a,b,c;
iii start = mp(0,0,0);
iii goal = mp(0,0,0);

void fill_grid(){
  fr(i,0,n){
    fr(j,0,n){
      grid[i][j] =((i*n + j)*a + b)%c;
    }
  }
}

int r[4] = {-1,0,0,1};
int c1[4] = {0,-1,1,0};


int bfs(){
  priority_queue<iii,vector<iii>,Comparator> q;
  q.push(start);
  start.C = 0;
  goal.C = -1;
  cost[start.A][start.B] = 1;
  while(!q.empty()){
    iii v = q.top();q.pop();

    if(cost[v.A][v.B]==5)
      continue;
    cout<<v.A<<" "<<v.B<<" "<<v.C<<endl;
    cost[v.A][v.B] = 5;
    if(v.A==goal.A && v.B==goal.B)
      return v.C;

    fr(i,0,4){
      int x = v.A + r[i];
      int y = v.B + c1[i];
      
      if(x>=0 && x<n && y>=0 && y<n){
	if(++cost[x][y]<=4){
	int tcost = grid[x][y]>=grid[v.A][v.B] ? 0 : grid[v.A][v.B] - grid[x][y];
	//if(==-1 || c > cost[v.A][v.B]+tcost){
	if(x==goal.A && y==goal.B)
	  tcost = grid[x][y]>=grid[v.A][v.B] ? grid[x][y]-grid[v.A][v.B] : grid[v.A][v.B] - grid[x][y];
	q.push( mp(x,y,tcost+v.C));
	  //}
	}
      }
    }
  }
  return -1;
}

int main(){
  cin>> n;
  grid.resize(n,vector<int> (n,0));
  cost.resize(n,vector<int> (n,-1));
  cin>>start.A>>start.B>>goal.A>>goal.B;
  start.A--;start.B--;goal.A--;goal.B--;
  cin>>a>>b>>c;

  fill_grid();
  fr(i,0,n){
    fr(j,0,n)
      cout<<grid[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  cout<<bfs();
}
