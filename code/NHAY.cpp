#include <iostream>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  string s,t;
  while(cin>>n){
    cin>>s>>t;
    bool flag=false;
    fr(i,0,t.size()){
      if(t[i]==s[0])
	flag=true;

      for(int j=0;j<s.size() && flag;j++){
	if(t[i+j]!=s[j]){
	  flag = false;
	  break;
	}
      }

      if(flag)
	cout<<i<<endl;
      flag = false;
    }
    cout<<endl;
  }
}
	
