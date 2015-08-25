#include<iostream>
#include<string>
using namespace std;

typedef long long ll;
#define fr(i,a,b) for(ll i=a;i<b;i++)

ll gcd(ll a,ll b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  string s;
  while(cin>>s && s[0]!='*'){
    ll ans = 1;
    fr(i,0,s.size()){
      if(s[i]=='Y'){
	ll g = gcd(ans,i+1);
	ans = ((i+1)*ans)/g;
      }
      else if(s[i]=='N' && ans%(i+1) == 0){
	ans = -1;
	break;
      }
    }

    cout<<ans<<endl;
  }
}
	 
