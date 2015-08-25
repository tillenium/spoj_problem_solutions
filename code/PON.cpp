//using miller rabin test to solve this
#include<iostream>
#include<math.h>
using namespace std;
typedef  unsigned long long  ULL;


ULL  mulmod(ULL a, ULL b, ULL c){
  ULL x = 0,y = a%c;

  while(b > 0){
    if(b%2==1)
      x = (x+y)%c;
    y = (y*2)%c;
    b/= 2;
  }
  return x % c;
}

ULL  modulo(ULL a,ULL b, ULL c){
  ULL x=1,y=a; // ULL is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=(x*y)%c;
    }
    y = (y*y)%c; // squaring the base
    b /= 2;
  }
  return x%c;
}


bool miller(ULL n){
  if(n<2)
    return false;
  if(n!=2 && n%2==0)
    return false;

  ULL s = n-1;
  while(s%2==0)
    s/=2;

  for(int i=0;i<18;i++){
    ULL a = rand()%(n-1) + 1,temn = s;
    ULL mod = modulo(a,temn,n);
    while(temn!=n-1 && mod!=1 && mod!=n-1){
      mod = mulmod(mod,mod,n);
      temn *= 2;
    }

    if(mod!=n-1 && temn%2==0)
      return false;
  }
  return true;
}
  


int main(){
  int t;ULL n;
  cin>>t;
  while(t--){
    cin>>n;
    if(miller(n))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}
