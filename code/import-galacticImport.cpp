#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second
#define mp(a,b) make_pair(a,b)

typedef pair<int,bool> ib;
int main(){

  int n;
  while(cin>>n){
    vector<vector<float> > value (n,vector<float> (n,-1.00));
    map<char,int> m;
    vector<int> toEarth(n);
    vector<string> process(n);
    //read
    vector<float> cost(n);
    fr(i,0,n){
      char planet;float c;string free;
      cin>>planet>>c>>free;
      m[planet] = i;
      cost[i] = c;
      process[i] = free;
    }

    fr(i,0,n){
      string free = process[i];
      fr(j,0,free.size()){
	if(free[j]=='*')
	  toEarth[i] = 1;
	else
	  value[i][m[free[i]]] = cost[i];
      }
    }

    fr(i,0,n){
      fr(j,0,n)
	cout<<value[i][j]<<" ";
      cout<<endl;
    }
    cout<<"to earth"<<endl;

    fr(i,0,n)
      cout<<toEarth[i]<<" ";
  }
}
      
