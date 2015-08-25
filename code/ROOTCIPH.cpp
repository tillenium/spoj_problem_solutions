#include<cstdio>

using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  long long a,b,c;
  while(t--){
    scanf("%lld%lld%lld",&a,&b,&c);

    long long ans = a*a - 2*b;
    printf("%lld\n",ans);
  }
}
