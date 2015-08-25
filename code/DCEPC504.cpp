#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
int main(){
  int t;cin>>t;
  ll n,k;
  while(t--){
    cin>>n>>k;
    vector<ll> parent;
    while(k!=1){
      parent.push_back(k);
      k = (k+1)/2;
    }
    parent.push_back(1);
    int ans = 0;
    for(int j = parent.size() - 2;j>=0 ;j--){
      if(parent[j] == parent[j+1]*2){
	ans = !ans;
      }
    }

    if(ans)
      cout<<"Female"<<endl;
    else
      cout<<"Male"<<endl;
    
  }
}
      
