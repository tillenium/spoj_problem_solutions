#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n && n){
    int count = 0;
    while(n){
      count++;
      n = n>>1;
    }
    cout<<count-1<<endl;
  }
}
