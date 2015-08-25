#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b) make_pair(a,b)
#define A first
#define B second

typedef pair<int,int> ii;

int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<ii> interval(n);

    fr(i,0,n){
      int a,b;cin>>a>>b;
      interval[i] = mp(b,a);
    }

    sort(interval.begin(),interval.end());

    int count = 1;
    ii prev = interval[0];
    fr(i,1,n){
      if(interval[i].B >= prev.A){
	prev = interval[i];
	count++;
      }
    }
    cout<<count<<endl;
  }
}
