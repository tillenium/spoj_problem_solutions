#include<iostream>
#include<string>

using namespace std;

bool palindrome(string s){
  int i=0,j=s.size()-1;
  while(i<=j){
    if(s[i]!=s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int main(){
  int t;cin>>t;
  string s;
  while(t--){
    cin>>s;
    if(palindrome(s))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}
    
