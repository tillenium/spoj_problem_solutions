#include<iostream>
using namespace std;
#define abs(a) ((a) > 0 ? (a) : -1*(a))

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
int main(){
  int t,a,b;
  cin>>t;
  while(t--){
    cin>>a>>b;
    cout<<(abs(a-b)) / gcd(abs(a),abs(b))<<endl;
  }
}
    
