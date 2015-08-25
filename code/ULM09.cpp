#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

//union find
int n;
typedef vector<int> vi;
vi set, r;
void UnionFind(){
  set.clear();r.clear();
  set.resize(n,0);
  r.resize(n,0);
  fr(i,0,n)
    set[i] = i;
}

int findSet(int i){
  return (set[i]==i) ? i : (set[i] = findSet(set[i]));
}

bool isSameSet(int i, int j){
  return findSet(i)==findSet(j);
}

void unionSet(int i,int j){
  if(isSameSet(i,j))
    return;
  int x = findSet(i);
  int y = findSet(j);

  if(r[x]>r[y]){
    set[y] = x;
  }
  else{
    set[x] = y;
    if(r[x]==r[y])
      r[y]++;
  }
}

//code for mst

#define cost first
#define A second.first
#define B second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

vector<iii> roads;
int mincost,m;

void mst(){
  mincost = 0;
  UnionFind();
  sort(roads.begin(),roads.end());
  int totalRoad = 0;
  fr(i,0,m){
    if(totalRoad>=n-1)
      return;
    iii v = roads[i];
    if(!isSameSet(v.A,v.B)){
      mincost += v.cost;
      unionSet(v.A,v.B);
      totalRoad++;
    }
  }
}
int main(){
  //n as number of juncitons
  //m as number of roads
  while(cin>>n>>m && m && n){
    roads.clear();
    roads.resize(m);
    int sumCost = 0;
    fr(i,0,m){
      iii road;
      cin>>road.A>>road.B>>road.cost;
      sumCost += road.cost;
      roads[i] = road;
    }
    mst();
    cout<<sumCost-mincost<<endl;
  }
}
