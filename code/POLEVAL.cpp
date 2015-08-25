#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
vector<int> co;
int n;

ll horner(int x){
  ll result = co[0];
  fr(i,1,n){
    result = result*x + co[i];
  }
  return result;
}
int main(){
  int ca = 1;
  while(cin>>n && n!=-1){
    co.clear();
    n++;
    co.resize(n);
    fr(i,0,n)
      cin>>co[i];

    int k;cin>>k;
    cout<<"Case "<<ca++<<":"<<endl;
    fr(i,0,k){
      int x;cin>>x;
      cout<<horner(x)<<endl;;
    }
  }
}
  
