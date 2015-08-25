#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

typedef vector<int> vi;
vi set(20000,0), r(20000,0), setSize(20000,1);
int n,numSets;

void UnionFind(){
  numSets = n;
  fr(i,0,n){
    r[i] = 0;
    setSize[i] = 1;
    set[i] = i;
  }
}

int findSet(int i){
  return (set[i]==i)  ? i: (set[i] = findSet(set[i]));
}

bool isSameSet(int i,int j){
  return findSet(i) == findSet(j);
}

void unionSet(int i,int j){
  //if(isSameSet(i,j))
  // return;
  numSets--;
  int x = findSet(i), y = findSet(j);
  //using rank to keep tree short
  if(r[x]>r[y]){
    set[y] = x;
    setSize[x] += setSize[y];
  }
  else {
    set[x] = y;
    setSize[y] +=setSize[x];
    if(r[x]==r[y])
      r[y]++;
  }
}

int sSize(int i){
  return setSize[findSet(i)];
}


#define A first
#define B second.first
#define flagged second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

typedef pair<int ,int> ii;
typedef pair<int,ii> iii;
vector<iii> roads(20000);
int q;
int pairs;
void unionAll(){
  UnionFind();
  fr(i,0,n-1){
    iii v = roads[i];
    if(!v.flagged){
      //if(!isSameSet(v.A,v.B)){
      //int x = findSet(v.A);
      //int y = findSet(v.B);
      int xsize = setSize[findSet(v.A)];
	int ysize = setSize[findSet(v.B)];
	pairs -= xsize*ysize;
	unionSet(v.A,v.B);
	//}
    }
  }
}

int main(){
  int t;cin>>t;
  while(t--){
    cin>>n;
    if(n<1){
      cout<<0<<endl<<endl;
      continue;
    }
    pairs = (n*(n-1))/2;

    fr(i,0,n-1){
      iii a;
      cin>>a.A>>a.B;
      a.A--;a.B--;
      a.flagged = 0;

      roads[i] = a;
    }
    typedef pair<char,int> ci;
    cin>>q;
    vector<ci> s(q,make_pair('Q',-1));
    int f;
    char c;
    //cout<<q<<endl;
    fr(i,0,q){
      cin>>c;
      s[i].first = c;
      //cout<<c<<" sdsdf"<<f<<endl;
      if(s[i].first=='R'){
	cin>>f;
	//cout<<f<<endl;
	f--;
	roads[f].flagged = 1;
	//ci.pop();
	s[i].second = f;
      }
    }
    unionAll();
    stack<int> ans;
    
    for(int i=s.size()-1;i>=0;i--){
      if(s[i].second==-1){
	ans.push(pairs);
	continue;
      }
      iii v = roads[s[i].second];
      //if(!isSameSet(v.A,v.B)){
	int xsize = sSize(v.A);
	int ysize = sSize(v.B);
	pairs -= xsize*ysize;
	unionSet(v.A,v.B);
	//}
    }
    while(!ans.empty()){
      cout<<ans.top()<<endl;
      ans.pop();
    }
    cout<<endl;
  }
}


