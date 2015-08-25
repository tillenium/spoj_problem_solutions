#include <iostream>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  int i,j;
  while(t--){
    cin>>i>>j;
    if(i>j){
      cout<<(j%2 ? 'D' : 'U')<<endl;
    }
    else{
      cout<<(i%2 ? 'R' : 'L')<<endl;
    }
  }
}
