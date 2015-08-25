#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))

typedef vector<int> vi;

vi in(26,0), out(26,0), color(26,0),found(26,0);
vector<vector<bool> > graph(26,vector<bool> (26,false));
string word;

bool isConnected(){
  queue<int> q;
  fr(i,0,26)
    color[i] = (found[i] ? 0 : 2);
  int i = 0;
  for(;color[i];i++);
  color[i] = 1;
  q.push(i);
  while(!q.empty()){
    i = q.front();q.pop();
    fr(j,0,26){
      if((graph[i][j] || graph[j][i]) && !color[j]){
	q.push(j);
	color[j] = 1;
      }
    }
    color[i] = 2;
  }

  fr(i,0,26)
    if(color[i]!=2)
      return false;

  return true;
}

bool hasEulerPath(){
  if(!isConnected()) return false;
  int x,y;x=y=0;

  fr(i,0,26){
    if(out[i] - in[i] == 1) x++;
    else if(in[i] - out[i] ==1) y++;
    else if(in[i] != out[i]) return false;
  }
  if((x+y==0) || (x==1 && y==1)) return true;
  return false;
}

int main(){
  int t;cin>>t;
  int u,v;
  while(t--){
    in.clear();
    in.resize(26,0);
    out.clear();
    out.resize(26,0);
    color.clear();
    color.resize(26,0);
    found.clear();
    found.resize(26,0);
    graph.clear();
    graph.resize(26,vector<bool> (26,0));
    int n;cin>>n;

    fr(i,0,n){
      cin>>word;
      u = word[0] - 'a'; v = word[word.size()-1]-'a';
      in[v]++;
      out[u]++;
      graph[u][v] = found[u] = found[v] = 1;
    }

    if(hasEulerPath())
      cout<<"Ordering is possible."<<endl;
    else
      cout<<"The door cannot be opened."<<endl;
    
  }
}
