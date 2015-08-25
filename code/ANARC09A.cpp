#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  string b;
  int c = 1;
  while(cin>>b && b[0]!='-'){
    stack<char> s;
    int ans = 0;

    fr(i,0,b.size()){
      if(b[i]=='{')
	s.push(b[i]);
      else{
	if(s.empty()){
	  ans += 1;
	  s.push('{');
	}
	else
	  s.pop();
      }
    }
    while(!s.empty()){
      s.pop();s.pop();
      ans++;
    }
    cout<<c++<<". "<<ans<<endl;
  }
}
    
	
