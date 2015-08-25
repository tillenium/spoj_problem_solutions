#include<iostream>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int gcd(int a, int b){
  return b ? gcd(b,a%b) : a;
}

int main(){
  int t;
  int a,b;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&a,&b);
    int n = gcd(a,b);
    int sq = sqrt(n);
    int ans = 0;
    fr(i,1,sq+1){
      if(n%i==0){
	ans += 2;
	if(i == n/i) ans --;
      }
    }
    printf("%d\n",ans);
  }
}
