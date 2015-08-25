#include<iostream>
#include<math.h>
using namespace std;

int main(){
  int t;cin>>t;
  long long n;
  while(t--){
    cin>>n;
    long long length = log2(n+1);
    long long start_num = pow(2,length) - 1;
    n = n - start_num;

    char arr[10000];
    int x = -1;

    while(n){
      if(n & 1)
	arr[++x] = '6';
      else
	arr[++x] = '5';

      n = n>>1;
    }

    for(int i=length-1;i>x;i--)
      cout<<"5";

    for(int i = x;i>=0;i--)
      cout<<arr[i];

    cout<<endl;
  }
}
    
    
    
