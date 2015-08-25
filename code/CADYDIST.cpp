#include<iostream>
#include<algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  long long n;
  while(cin>>n && n){
    long long c[n];
    long long p[n];

    fr(i,0,n)
      cin>>c[i];
    fr(i,0,n)
      cin>>p[i];

    sort(c,c+n);
    sort(p,p+n);

    long long ans = 0;
    fr(i,0,n){
      ans += c[i] * p[n - i - 1];
    }

    cout<<ans<<endl;
  }
}
