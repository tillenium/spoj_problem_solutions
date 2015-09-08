#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  long long t;scanf("%lld",&t);
  long long ans = 0;
  long long  n;
  while(t--){
    scanf("%lld",&n);
    ans ^= n;
  }
  cout<<(ans^0)<<endl;
}
