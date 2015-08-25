#include<iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

vector<int> p (1001,1);
vector<int> prime;
void setPrime(){
  fr(num,2,501){
    if(p[num])
    for(int loc=num*2;loc<1001;loc += num)
      p[loc] = 0;
  }

  fr(i,2,1001)
    if(p[i]){

      prime.push_back(i);
    }
}
  
  

int main(){
  setPrime();
  int t;cin>>t;
  while(t--){
    int n;cin>>n;

    int i =0;
    int pf = prime[i++];
    int ans = n;

    while(pf*pf <= n){
      if(n%pf==0) ans -= ans/pf;
      while(n%pf==0) n /= pf;
      if(i==prime.size())
	break;
      pf = prime[i++];
    }

    if(n!=1)
      ans -= ans/n;
    cout<<ans<<endl;
  }
}
