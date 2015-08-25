#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
//code for UFDS
typedef vector<int> vi;
vi s,r,setSize;
int n,numSets;

void UnionFind(){
  setSize.clear();
  s.clear();
  r.clear();
  setSize.resize(n,1);
  r.resize(n,0);
  s.resize(n,0);
  numSets = n;
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
#define mp(a,b,c) make_pair(a,make_pair(b,c))

typedef pair<int,int> ii;
typedef pair<long,ii> iii;

vector<iii> edges;
int t;
long p;

long approx(double x){
  if(x-(long)x==0)
  return (long)x;
  return (long)(x+1);
}

long dist(ii a, ii b){
  //cout<<a.first<<" "<<b.first<<" "<<a.second<<" "<<b.second<<endl;
  double d = sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second))*p;
  //cout<<"d: "<<d<<endl;
  return approx(d);
}

int mini;
bool pluss = false;

void mst(){
UnionFind();
sort(edges.begin(),edges.end());
int stop = 1;
fr(i,0,edges.size()){
if(stop==n)
  return;
iii v= edges[i];
if(!isSameSet(v.A,v.B)){
mini = (mini+v.cost);
if(mini>1000000000){
mini = mini%1000000000;
pluss = true;
}
unionSet(v.A,v.B);
}
}
}

int main(){
cin>>t;
fr(c,1,t+1){
mini = 0;
cin>>n>>p;
edges.clear();
//edges.resize((n*(n-1))/2);
int x,y;
vector<ii> nodes(n);
fr(i,0,n){
cin>>x>>y;
nodes[i] = make_pair(x,y);
}

fr(i,0,n){
fr(j,i+1,n){
edges.push_back(mp(dist(nodes[i],nodes[j]),i,j));

//cout<<edges[edges.cxsize()-1].A<<" "<<edges[edges.size()-1].B<<" "<<edges[edges.size()-1].cost<<endl;
}
}

//fr(i,0,edges.size())
//cout<<edges[i].A<<" "<<edges[i].B<<" "<<edges[i].cost<<endl;
 mst();
 if(pluss)
 mini =(mini%1000000000)+ 7;
cout<<"Scenario #"<<c<<": "<<mini<<endl;
}
}

