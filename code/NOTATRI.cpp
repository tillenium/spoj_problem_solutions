#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  while(cin>>n && n){
    int arr[n];
    vector<int> h(1000001,0);
    fr(i,0,n){
      cin>>arr[i];
      h[arr[i]]++;
    }

    sort(arr,arr+n);

    fr(i,1,1000001)
      h[i] += h[i-1];

    long long ans = 0;
    fr(i,0,n){
      fr(j,i+1,n-1){
	if(arr[i] + arr[j] <= 1000000)
	  ans += h[arr[n-1]] - h[arr[i] + arr[j]];
      }
    }

    cout<<ans<<endl;
  }
}
