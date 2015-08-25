#include<iostream>
#include<vector>
using namespace std;

int main(){
  long n;cin>>n;
  if(n==0){
    cout<<n<<endl;
    return 0;
  }
    
  vector<int> ans;
  while(n){
    int r;
    if(n>0){
      r = (n%-2);
      n = n / -2;
    }
    else{
      r = -(n%-2);
      n = (n-1)/-2;
    }
    ans.push_back(r);
  }
  for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i];
  cout<<endl;
}
