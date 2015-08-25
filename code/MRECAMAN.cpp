#include<iostream>
#include <vector>
#include <bitset>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  bitset<10000001> p;
  vector<int> rs(500001);
  rs[0] = 0;
  p[0] = 1;
  fr(i,1,500001){
    rs[i] = rs[i-1] - i;
    if(rs[i] < 0 || p[rs[i]])
      rs[i] = rs[i-1] + i;
    p[rs[i]] = 1;

  }
  
  int k;
  while(cin>>k && k!=-1){
    cout<<rs[k]<<endl;
  }
  
}
