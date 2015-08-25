#include<iostream>
using namespace std;

int main(){
  int t;int n, m;
  cin>>t;
  while(t--){
    cin>>n>>m;

    int a = n-m;
    int b = (m-1)/2;
    cout<<((a & b) == 0)<<endl;
  }
}
