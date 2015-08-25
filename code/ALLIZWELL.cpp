#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define visited = 1;

bool dfsTraversal(vector<vector<char> >adjMatrix,int n,int m,vector<vector<int> > &isVisited, int si,int sj,string all,int index){
  if(si>=n || sj>=m || si<0 || sj<0)
    return false;
  //cout<<si<<" "<<sj<<adjMatrix[si][sj]<<all[index]<<endl;
  isVisited[si][sj] = 1;
  if(all[index]==adjMatrix[si][sj])
    index++;
  else{
    isVisited[si][sj] = 0;
    return false;
  }

  if(index==10)
    return true;

  for(int i=si-1;i<=si+1;i++){
    for(int j=sj-1;j<=sj+1;j++){
      //cout<<i<<" - "<<j<<" ";
      if((i<n && j<m && i>=0 && j>=0)  && isVisited[i][j]!=1){
	//cout<<i<<" ## "<<j<<" ";
	if(dfsTraversal(adjMatrix,n,m,isVisited,i,j,all,index))
	  return true;
      }
    }
  }
  isVisited[si][sj] = 0;
  return false;
}

bool dfs(vector<vector<char> >adjMatrix,int n,int m){

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      //cout<<i<<": "<<j<<endl;
	vector<vector<int> > isVisited(n, vector<int> (m,0));
      
	if(dfsTraversal(adjMatrix,n,m,isVisited,i,j, "ALLIZZWELL",0))
	  return true;
    }
  }

  return false;
}

  

int main(){

  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    char c;
    vector<vector<char> > adjMatrix(n, vector<char> (m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
	cin>>c;
	adjMatrix[i][j] = c;
      }

    if(dfs(adjMatrix,n,m))
       cout<<"YES\n";
    else
      cout<<"NO\n";
  }
}
