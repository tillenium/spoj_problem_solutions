#include<cstdio>
#include<vector>
using namespace std;

#define fr(i,a,b) for(long long i=a;i<b;i++)
#define p(a,b) printf("%lld %lld\n",a,b)
#define s(a) scanf("%lld",&a)
int main(){

  long long  t;s(t);
  while(t--){
    long long  n,m;s(n),s(m);

    vector<long long> arr(n);
    fr(i,0,n)
      s(arr[i]);

    long long  total = 0,station = 0;

    long long  i = 0,j =0, maxsum = 0;
    while(i<=j && j < n){
      maxsum += arr[j++];
      while(maxsum > m){
	maxsum -= arr[i++];
      }
      if(maxsum <= m &&  (j - i >= station)){
	if((j-i==station && maxsum < total) || j-i!=station)
	  total = maxsum;
	station = j -i;
      }
    }

    p(total,station);
  }
}
