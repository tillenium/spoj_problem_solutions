#include <iostream>
#include<vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int k,l,m;

  cin>>k>>l>>m;
  vector<bool> awins(1000001,false);
  awins[1] = awins[k] = awins[l] = true;
  fr(i,2,k)
    awins[i] = !(awins[i-1]);
  fr(i,k+1,l)
    awins[i] = !(awins[i-1] && awins[i-k]);
  fr(i,l+1,1000001){
    awins[i] = !(awins[i-l] && awins[i-k] && awins[i-1]);
  }
  int n;
  fr(i,0,m){
    cin>>n;
    if(awins[n])
      cout<<'A';
    else
      cout<<'B';
  }
}
  
