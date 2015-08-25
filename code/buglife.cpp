# include <iostream>
# include <vector>
# include <queue>

#define M 1
#define F 0
using namespace std;

typedef vector<int> vi;
vector<vi> adjList;
vector<int> sex;

bool bipariteChech(int start){
  queue<int> q;
  q.push(start);
  sex[start] = M;
  while(!q.empty()){
    int u = q.front();q.pop();
    for(int i=0;i<adjList[u].size();i++){
      int v = adjList[u][i];
      if(sex[v]==-1){
	sex[v] = (sex[u]==M)? F : M;
	q.push(v);
      }
      else{
	if(sex[u]==sex[v])
	  return false;
      }
    }
  }
  return true;
}

int main(){
  int t;cin>>t;
  int n,c,u,v,a;
  a = 1;
  while(t--){
    cin>>n>>c;
    adjList.erase(adjList.begin(),adjList.end());
    adjList.resize(n,vi(0));
    for(int i=0;i<c;i++){
      cin>>u>>v;
      u--;v--;
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    sex.erase(sex.begin(),sex.end());
    sex.resize(n,-1);
    
    bool flag = true;
    for(int i=0;i<n;i++){
  bool ans = true;
  if(sex[i]==-1){
    ans  = bipariteChech(i);
}
  if(ans==false){
  flag = false;
  break;
}
}
    printf("Scenario #%d:\n",a);
    if (!flag)
      printf("Suspicious bugs found!\n");
    else
      printf("No suspicious bugs found!\n");
    a++;
  }
}
