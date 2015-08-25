#include <iostream>
#include <vector>

using namespace std;

int rd[4] = {-1,0,0,1};
int cd[4] = {0,-1,1,0};

int r,c;
vector<vector<char> > adjMatrix;
vector<vector<bool> > visited;
int total_max;

int dfs(int i,int j){
  //cout<<i<<" "<<j<<endl;
  int max = 0;
  int secondMax = 0;
  int size = 0;
  visited[i][j] =true;
  int m,n;
  for(int d=0;d<4;d++){
    m = i + rd[d];
    n = j + cd[d];
    if(m<r && m>=0 && n<c && n >= 0)
      if(!visited[m][n] && adjMatrix[m][n]=='.'){

	//visited[m][n] =true;
	size = dfs(m,n);
	if(size>max){
	  secondMax = max;
	  max = size;
	}
	else if(size>secondMax)
	  secondMax = size;
      }
  }
  if(total_max < (max+secondMax + 1))
    total_max = max+secondMax + 1;
  //cout<<i<<" "<<j<<endl;
  //cout<<max+1<<" "<<total_max<<endl;
  return max+1;

}


int main(){
  int t,max;cin>>t;
  int starti,startj;
  while(t--){
    cin>>c>>r;
    total_max = 0;
    //adjMatrix.erase(adjMatrix.begin(),adjMatrix.end());
    adjMatrix.clear();
    adjMatrix.resize(r,vector<char> (c));

    visited.clear();
    //visited.erase(visited.begin(),visited.end());
    visited.resize(r,vector<bool> (c,false));
    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++){
	cin>>adjMatrix[i][j];
	if(adjMatrix[i][j]=='.'){
	  starti = i;
	  startj = j;
	}
      }

    max = dfs(starti,startj);
    if(max > total_max)
      total_max = max;

    printf("Maximum rope length is %d.\n",total_max-1);

  }
}

