#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  vector<int> num(34000,1);
  vector<int> ans;
  fr(i,2,34000){
    if(num[i]){
      int x = 1;
      for(int j=i+1;j<34000;j++){
	if(num[j]){
	  if(x==0){
	    num[j] = 0;
	  }
	  x = (x+1)%i;
	}
      }
      ans.push_back(i);
    }
  }
  int n;
  while(cin>>n && n){
    cout<<ans[n-1]<<endl;
  }
}
	  
      
