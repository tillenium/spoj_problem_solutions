#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    string s;cin>>s;

    int i=0,j=1;
    while(j<s.size()){
      int k = 0;
      for(;k<s.size() && s[(k+i)%s.size()] == s[(k+j)%s.size()];k++);

      if(k==s.size())
	break;

      if(s[(k+i)%s.size()] > s[(k+j)%s.size()])
	i = j++;
      else
	j += k + 1;
    }

    cout<<i+1<<endl;
  }
}
	
