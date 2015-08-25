#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    int arr[n*2];
    map<int,int> m;
    for(int i=0;i<2*n;){
      int s,e;cin>>s>>e;
      m[s] = 1;
      m[e] = -1;
      arr[i++] = s;
      arr[i++] = e;
    }

    sort(arr,arr+n*2);

    int count[n*2];
    
    fr(i,0,2*n){
      if(m[arr[i]]==1)
	count[i] = 1;
      else
	count[i] = -1;
    }

    fr(i,1,2*n)
      count[i] += count[i-1];

    int ans = 0;
    fr(i,0,2*n)
      if(count[i] > ans)
	ans = count[i];

    cout<<ans<<endl;
  }
}
    
  
  
