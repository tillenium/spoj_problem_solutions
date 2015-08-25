#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n,m;cin>>n>>m;
  vector<int> arr(n);
  fr(i,0,n)
    cin>>arr[i];

  int ans = 0;

  int i=0,j=0,sum=arr[j];
  while(i<=j){

    if(sum<=m){
      if(ans < sum)
	ans = sum;
      if(j==n-1)
	break;
    }
    if(sum > m)
      sum -= arr[i],i++;
    else if(j!=n-1)
      sum += arr[++j];
  }
  cout<<ans;
}
