#include<iostream>
#include<vector>

using namespace std;

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  int t;cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    int x = gcd(a,b);
    cout<<b/x<<" "<<a/x<<endl;
  }
}
