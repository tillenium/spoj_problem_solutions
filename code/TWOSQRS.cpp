#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  vector<int> p(1000001,1);
  vector<int> prime;
  fr(i,2,1000001){
    if(p[i]){
      for(int j=i*2;j<1000001;j += i){
	p[j] = 0;
      }
      prime.push_back(i);
    }
  }

  int t;cin>>t;
  long long n;
  while(t--){
    cin>>n;
    bool flag = false;
    fr(i,0,prime.size()){
      if(n%4==3){
	flag = true;break;
      }
      if(prime[i]*prime[i] > n)
	break;
      if(n%prime[i]==0){
	int power = 0;
	while(n%prime[i]==0){
	  power++;
	  n /= prime[i];
	}
	if(prime[i]%4== 3 &&  power%2){
	  flag = true;
	  break;
	}
      }
    }
    if(flag)
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }
  
}
