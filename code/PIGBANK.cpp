#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))


int main(){
  int t;
  cin>>t;
  while(t--){
    int e,f;cin>>e>>f;
    int total = f-e;
    int n;cin>>n;
    vector<int> w(n);
    vector<int> p(n);
    fr(i,0,n){
      int a,b;
      cin>>a>>b;
      p[i] =a;w[i] = b;
    }
    vector<int> K(total+1,-1);

    int m = 1000000000;
    K[0] = 0;
    fr(i,1,total+1){
      m = 1000000000;
      fr(j,0,n){
	if(i>=w[j]){
	  m = min(m,K[i-w[j]] + p[j]);
	}
      }
      K[i] = m;
    }
    if(K[total]==1000000000)
      cout<<"This is impossible.\n";
    else
      cout<<"The minimum amount of money in the piggy-bank is "<<K[total]<<"."<<endl;
  }
}
      
