#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;cin>>n;
  vector<float>pizza(n);
  fr(i,0,n){
    string s;cin>>s;
    if(s[2]=='2')
      pizza[i] = 0.5;
    else if(s[0]=='1')
      pizza[i] = 0.25;
    else
      pizza[i] = 0.75;
  }
  sort(pizza.begin(),pizza.end());
  int i = 0,j=n-1;
  int ans = 0;
  float rem = 0;
  while(i<=j){
    if(pizza[i]<=rem){
      rem -= pizza[i];
      i++;
    }
    else if(pizza[i]+pizza[j]<=1){
      rem = 1 - pizza[i] - pizza[j];
      i++;
      j--;
      ans += 1;
    }
    else{
      rem = 1 - pizza[j--];
      ans += 1;
    }
  }
  cout<<ans+1;
}
