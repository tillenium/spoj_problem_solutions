#include<iostream>
using namespace std;

typedef unsigned long long ul;

ul gcd(ul a, ul b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  ul a,b;
  while(cin>>a>>b && a && b){
    ul n = a*b;
    ul g = gcd(a,b);
    n /= g;
    n /= g;

    cout<<n<<endl;
  }
}
