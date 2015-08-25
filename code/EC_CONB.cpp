#include<iostream>
using namespace std;

int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;

    if(n%2!=0){
      cout<<n<<endl;
      continue;
    }
    int ans = 0;

    while(n!=0){
      if(n & 1)
	ans =(ans<<1) | 1;
      else
	ans <<= 1;
      n >>= 1;
    }

    cout<<ans<<endl;
  }
}
