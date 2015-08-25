#include<iostream>
#include<string>
#include<map>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

map<char,int> m;


int toNumber(string s){
  int ans = 0;
  int mul = 1;
  fr(i,0,s.size()){
    if(s[i]=='m' || s[i]=='c' || s[i]=='x' || s[i]=='i'){
      ans += mul * m[s[i]];
      mul = 1;
    }
    else{
      mul = s[i] - '0';
    }
  }
  return ans;
}

string to_mcxi(int n){
  char arr[4] = {'m','c','x','i'};
  string ans = "";
  int mul,rem;
  fr(i,0,4){
    if(n >= m[arr[i]]){
      mul = n/m[arr[i]];
      if(mul==1)
	ans = ans +  arr[i];
      else
	ans = ans +  char(mul + '0') + arr[i];
      n = n%m[arr[i]];
    }
  }
  return ans;
}

int main(){
  int t;
  string a,b;
  m['m'] = 1000;
  m['c'] = 100;
  m['x'] = 10;
  m['i'] = 1;
  cin>>t;
  while(t--){
    cin>>a>>b;
    cout<<to_mcxi(toNumber(a) + toNumber(b))<<endl;
  }
}
