#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define A first
#define B second.first
#define C second.second.first
#define cost second.second.second
#define mp(a,b,c,d) make_pair(a,make_pair(b,make_pair(c,d)))
#define fr(i,a,b) for(int i=a;i<b;i++)

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<int,iii> iv;

vector< vector<char> > board;
vector< vector< vector <int> > > visited;
int n,p1,p2,p3;

int bfs(){
  queue<iv> q;
  q.push(mp(p1,p2,p3,0));
  visited[p1][p2][p3] = 1;
  while(!q.empty()){
    iv u = q.front();q.pop();
    if(u.A==u.B && u.B==u.C)
      return u.cost;

    fr(i,0,n){
      if(i!=u.A && board[u.A][i]==board[u.B][u.C] && !visited[i][u.B][u.C]){
	visited[i][u.B][u.C] = 1;
	q.push(mp(i,u.B,u.C,u.cost+1));
      }
      if(i!=u.B && board[u.B][i]==board[u.A][u.C] && !visited[u.A][i][u.C]){
	visited[u.A][i][u.C] = 1;
	q.push(mp(u.A,i,u.C,u.cost+1));
      }
      if(i!=u.C && board[u.C][i]==board[u.A][u.B] && !visited[u.A][u.B][i]){
	visited[u.A][u.B][i]=1;
	q.push(mp(u.A,u.B,i,u.cost+1));
      }
    }
  }
  return -1;
}
  


int main(){
  board.resize(50, vector<char> (50,0));
  while(cin>>n && n){
    cin>>p1>>p2>>p3;p1--;p2--;p3--;
    visited.clear();
    visited.resize(n, vector< vector<int> > (n, vector<int> (n,0)));
    fr(i,0,n)
      fr(j,0,n)
      cin>>board[i][j];

    int ans = bfs();
    if (ans==-1) printf("impossible\n");
    else printf("%d\n",ans);
  }
}

    
    
