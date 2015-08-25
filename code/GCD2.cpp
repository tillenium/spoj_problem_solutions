#include <iostream>
#include <string>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
int mod(string b,int a){
  int x = 0;
  fr(i,0,b.size()){
    x = 10*x + (b[i] - '0');
    x %= a;
  }
  return x;
}

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  int t;cin>>t;
  while(t--){
    int a;string b;
    cin>>a>>b;
    if(a==0)
      cout<<b<<endl;
    else
      cout<<gcd(a,mod(b,a))<<endl;
  }
}
