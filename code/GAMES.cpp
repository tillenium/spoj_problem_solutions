#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string s; cin>>s;

    int i=0;
    while(i<s.size() && s[i++]!='.');

    if(i==s.size())
      cout<<1<<endl;
    else{
      int base = (int) pow(10,s.size()-i);
      int n = 0;
      while(i!=s.size()){
	n = 10*n + (s[i++] - '0');
      }

      int g = gcd(base,n);
      cout<<base/g<<endl;
    }
  }
}

    
