#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(){
  string input;
  while(cin>>input && input!= "00e0"){
    int n = (input[0]-'0')*10 + (input[1]-'0');
    n = n * pow(10,(input[3]-'0'));

    if(n==0)
      cout<<0<<endl;
    else{
      long long  power = 2;
      while(power<=n){
	power = power<<1;
      }
      power = power>>1;
      cout<<1 + (2 * (n-power))<<endl;
    }
  }
}
    
    
