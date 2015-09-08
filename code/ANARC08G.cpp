#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int in = 1,n;
  while(scanf("%d",&n) && n){
    vector<int> g(n,0);
    int total = 0;
    fr(i,0,n){
      fr(j,0,n){
	int x;scanf("%d",&x);
	g[i] += x;
	g[j] -= x;
	total += x;
      }
    }
    int optimised = 0;
    fr(i,0,n)
      if(g[i]>0)
	optimised += g[i];

    cout<<in++<<". "<<total<<" "<<optimised<<endl;
  }
}

	

    

    
  
