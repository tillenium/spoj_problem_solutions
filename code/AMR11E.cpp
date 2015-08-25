#include<iostream>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){

  vector<int> lucky;
  vector<int> p(3000,0);
  fr(i,2,3000){
    if(p[i]==0){
      for(int j=i*2;j<3000;j+= i)
	p[j]++;
    }
    if(p[i]>=3)
      lucky.push_back(i);
  }

  int t;cin>>t;int n;
  while(t--){
    cin>>n;
    cout<<lucky[n-1]<<endl;
  }

}
  
