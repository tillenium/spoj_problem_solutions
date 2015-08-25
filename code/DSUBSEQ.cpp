#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
int main(){
  int t;
  string s;
  cin>>t;
  while(t--){
    cin>>s;
    vector<int> prev(26,0);
    vector<int> ans(s.size()+1,0);
    ans[0] = 1;
    fr(i,1,s.size()+1){
      ans[i] = (ans[i-1]*2)%1000000007;
      if(prev[s[i-1]-'A']!=0){
	ans[i] = (1000000007 + ans[i] -  ans[prev[s[i-1]-'A']-1])%1000000007;
      }
      prev[s[i-1]-'A'] = i;
    }

    cout<<ans[s.size()]%1000000007<<endl;
  }
}
