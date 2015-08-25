#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define A first
#define B second

typedef pair<int,int> ii;

ii start;
ii goal;

int r[8] = {-2,-2,-1,-1,1,1,2,2};
int c[8] = {-1,1,-2,2,-2,2,-1,1};
int bfs(){
  vector< vector<int> >visited(8,vector<int> (8,-1));
  queue<ii> q;
  int x,y;
  q.push(start);
  visited[start.A][start.B]=0;
  while(!q.empty()){
    ii v = q.front();q.pop();
    if(v.A==goal.A && v.B==goal.B)
      return visited[goal.A][goal.B];

    fr(i,0,8){
      x = v.A+r[i];
      y = v.B+c[i];

      if(x>=0 && x<8 && y>=0 && y<8){
	if(visited[x][y]==-1 || visited[x][y] > visited[v.A][v.B]+1){
	  visited[x][y] = visited[v.A][v.B] + 1;
	  q.push(mp(x,y));
	}
      }
    }
  }
  return -1;
}

int main(){
  int t;cin>>t;
  while(t--){
    char c;
    cin>>c;
    start.B = c-'a';cin>>c;
    start.A = c-'1';cin>>c;
    goal.B = c-'a';cin>>c;
    goal.A = c-'1';

    cout<<bfs()<<endl;
  }
}
