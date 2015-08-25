#include<iostream>
#include<vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  while(t--){
    int n,m,d,h;
    cin>>n>>m>>d;
    fr(i,0,n){
      cin>>h;
      if(h%d==0)
	m -= (h/d - 1);
      else
	m -= h/d;
    }

    if(m<=0)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
}
