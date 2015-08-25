#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? b : a)
int main(){
  int t,n,k;
  cin>>t;
  while(t--){
    cin>>n>>k;
    vector<int> a(n);
    fr(i,0,n)
      cin>>a[i];

    sort(a.begin(),a.end());

    int m = 1000000000;
    fr(i,0,n-k+1){
      m = min(m,a[i+k-1] - a[i]);
    }
    cout<<m<<endl;
  }
}
    
    
