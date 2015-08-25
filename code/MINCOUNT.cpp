#include<iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
  ull t,n;
  cin>>t;
  while(t--){
    cin>>n;
    ull ans = (n%2 ? ((n+1)/2)*(n) : ((n)/2)*(n+1));
    cout<<ans/3<<endl;
  }
}
     
