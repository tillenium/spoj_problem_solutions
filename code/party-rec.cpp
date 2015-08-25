#include <iostream>
#include <vector>
using namespace std;

int n,fee;
vector<int> fees;
vector<int> fun;
int maxfee, maxfun;

void dp(int i,int fe, int fu){
  if(i==n || fe - fee[i]<0){
    if(fu>maxfun){
      maxfun = fu;
      maxfee = fe;
    }
    return;
  }
  dp(i,
    
}

int main(){
  while(cin>>fee>>n && fee && n){
    fees.clear();maxfee = maxfun = 0;
    fees.resize(n);
    fun.clear();fun.resize(n);
    for(int i=0;i<n;i++)
      cin>>fees[i]>>fun[i];
  }
}
