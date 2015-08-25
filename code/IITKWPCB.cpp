#include<cstdio>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  int t;scanf("%d",&t);
  ll n;
  while(t--){
    scanf("%lld",&n);

    if(n==1){
      printf("0\n");
      continue;
    }
    for(ll j = n/2; j>=1;j--){
      if(gcd(j,n)==1){
	printf("%lld\n",j);
	break;
      }
    }
  }
}
      
    

    
