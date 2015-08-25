#include<iostream>
using namespace std;

int main(){
  unsigned long long n;
  while(cin>>n && n){
    cout<<5 + 7*(n-1) + 3 * ((n-1)*(n-2))/2<<endl;
  }
}
