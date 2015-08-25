#include<iostream>
#include<math.h>
using namespace std;

int main(){
  long long int a;
  int t;
  cin>>t;
  while(t--){
    cin>>a;
    if(a==0||a==1||a==2)
      cout<<1<<endl;
    else
      cout<<(long long int)floor((log(2*acos(-1)*a)/2+a*(log(a)-1))/log(10))+1<<endl;
  }
}
