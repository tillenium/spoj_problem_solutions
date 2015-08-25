#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)


//code for UFDS
typedef vector<int> vi;
vi s,r,setSize;
int n,numSets;

void UnionFind(){
  setSize.assign(n,1);numSets = n;r.assign(n,0);
  s.assign(n,0);
  fr(i,0,n)
    s[i] = i;
}

int findSet(int i){
  return (s[i]==i)? i : (s[i]=findSet(s[i]));
}

bool isSameSet(int i,int j){
  return findSet(i)==findSet(j);
}

void unionSet(int i,int j){
  if(isSameSet(i,j))
    return;
  numSets--;
  int x = findSet(i), y = findSet(j);
  //using rank to keep tree short
  if(r[x]>r[y]){
    s[y] = x;
    setSize[x] += setSize[y];
  }
  else {
    s[x] = y;
    setSize[y] +=setSize[x];
    if(r[x]==r[y])
      r[y]++;
  }
}

int numOfSets(){
  return numSets;
}

//now code for mst begins
#define cost first
#define A second.first
#define B second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c));
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<iii> edges;
int m,p,t,minn;

void mst(){
  sort(edges.begin(),edges.end());
  UnionFind();
  int processedEdges = 1;
  fr(i,0,m){
    iii v = edges[i];
    if(processedEdges == n)
      return;
    if(!isSameSet(v.A,v.B)){
      //cout<<v.A<<" "<<v.B<<endl;
      minn += v.cost;
      processedEdges++;
      unionSet(v.A,v.B);
    }
  }
}


int main(){
  cin>>t;
  int a,b,c;
  while(t--){
    cin>>p>>n>>m;
    edges.clear();
    edges.resize(m);
    minn=0;
    fr(i,0,m){
      cin>>a>>b>>c;a--;b--;
      iii e = mp(c,a,b);
      edges[i]=e;
    }
    mst();
    cout<<minn*p<<endl;
  }
}
      
  

  
