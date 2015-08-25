#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second.first
#define C second.second
#define RESIZE(a,b) resize(a,vector<int> (b,0))
#define mp(i,j,k) (make_pair(i,make_pair(j,k)))
#define MIN(a,b) ((a) > (b) ? b : a)
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector< vector<int> > cube;
vector<vector<int> > visited;

int m,n,t,filled;


int bfs(int x,int y){
  queue<iii> q;
  q.push(mp(x,y,0));
  //visited[i][j] = 1;
  while(!q.empty()){
    ii v = q.front(); q.pop();
    visited[v.A][v.B] = 1;
    if(v.A != 0 && v.A != m-1 && v.B!=0 && v.B!=n-1){
      int min = MIN(cube[v.A-1][v.B],MIN(cube[v.A+1][v.B],MIN(cube[v.A][v.B-1],cube[v.A][v.B+1])));
      //cout<<min<<endl;
      if(min>cube[v.A][v.B]){
	filled += min - cube[v.A][v.B];
	cube[v.A][v.B] = min;
      }
    }

    fr(i,-1,1){
      fr(j,-1,1){
	if((i!=0 || j !=0) && v.A+i>=0 && v.A+i<m && v.B+j>=0 && v.B+j<n){

	  if(!visited[v.A][v.B]){
	    if(cube[v.A][v.B] > cube[v.A+i][v.B+j])
	      q.push(mp(v.A+i,v.B+j));
	  }
	}
      }
    }
  }
}

void components(){
  fr(i,0,m)
    fr(j,0,n)
    bfs(i,j);

}
int main(){
  cin>>t;
  while(t--){
    cin>>m>>n;
    filled = 0;
    cube.clear();
    cube.RESIZE(m,n);

    visited.clear();
    visited.RESIZE(m,n);
    
    fr(i,0,m)
      fr(j,0,n)
      cin>>cube[i][j];

    components();
    cout<<filled<<endl;
  }
}
