#include <iostream>
#include <vector>

using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define MAX(a,b) ((a) > (b) ? a : b)
int main(){
  int t;cin>>t;
  int n;
  while(t--){
    cin>>n;
    vector<int> mem(n,1);
    vector<int> number(n);
    vector<int> mem2(n,1);
    vector<int> num2(n);
    fr(i,0,n){
      cin>>number[i];
      num2[n-1-i] = number[i];
    }

    int max = 0;
    fr(i,0,n){
      for(int j=i-1;j>=0;j--){
	if(number[i] > number[j]){
	  mem[i] = MAX(mem[i],1+mem[j]);
	}
      }
    }

    for(int i=n-1;i>=0;i--){
      for(int j=i+1;j<n;j++){
	if(number[i] > number[j]){
	  mem2[i] = MAX(mem2[i],1 + mem2[j]);
	}
      }

    }

    fr(i,0,n)
      if(mem[i]+mem2[i]-1 > max)
	max = mem[i] + mem2[i] - 1;

    cout<<max<<endl;

  }
}
