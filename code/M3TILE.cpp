#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<int> ans(31,0);
  ans[0] = 1;
  ans[1] = 0;
  ans[2] = 3;
  ans[4] = 11;

  for(int i=6;i<31;i += 2){
    ans[i] = 3 * ans[i-2];
    for(int j = i-4;j>=0;j--){
      ans[i] += 2 * ans[j];
    }
  }
  int n;
  while(cin>>n && n!=-1)
    cout<<ans[n]<<endl;
}
