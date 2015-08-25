#include <iostream>
#include <vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  vector<int> a(10);
  fr(i,0,10){
    cin>>a[i];
  }
  
  fr(i,1,10){
    a[i] += a[i-1];
  }
  int diff = 100 - a[0];
  int num = a[0];
  fr(i,1,10){
    int k = abs(100-a[i]);
    if(k<diff || (k==diff && a[i] > num)){
	num = a[i];
	diff = k;
      }
  }
  cout<<num;
}
	  
