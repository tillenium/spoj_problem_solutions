#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second
#define mp(i,j) make_pair(i,j)

typedef pair<int,int> ii;

int f,s,g,u,d;

int steps(){
  queue<int> q;
  q.push(s);
  vector<int> cost(f,-1);
  cost[s] = 0;
  if(s==g)
    return 0;
  while(!q.empty()){
    int v = q.front();q.pop();
    
    if(v+u<f)
      if(v+u==g)
	return cost[v]+1;
      else
	if(cost[v+u]==-1 || cost[v+u] > cost[v]+1){
	  cost[v+u] = cost[v]+1;
	  q.push(v+u);
	}

    if(v-d>=0)
      if(v-d==g)
	return cost[v] + 1;
      else
	if(cost[v-d]==-1 || cost[v-d] > cost[v]+1){
	  cost[v-d] = cost[v]+1;
	  q.push(v-d);
	}
  }
  return -1;
}

int main(){
  cin>>f>>s>>g>>u>>d;
  g--;s--;
  int n = steps();
  if(n==-1)
    cout<<"use the stairs";
  else
    cout<<n;
}


	
   
    
