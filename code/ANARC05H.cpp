#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define val(c) (c-'0')

string s;
vector<vector<vector<int> > > dp(30,vector<vector<int> >(250, vector<int> (250,0)));

int f(int i,int sum,int pre){
  if(i==s.size()){
    if(sum<pre)
      return 0;
    else
      return 1;
  }
  int ans = f(i+1,sum+val(s[i]), pre);
  if(sum>=pre)
    ans += f(i+1,val(s[i]),sum);
  return ans;
}

int main(){
  int in = 1;
  while(cin>>s && s!= "bye"){
    dp.clear(); dp.resize(30,vector<vector<int> >(250, vector<int> (250,0)));
    cout<<in++<<". ";
    cout<<f(1,val(s[0]),0)<<endl;
  }
}
    
    
