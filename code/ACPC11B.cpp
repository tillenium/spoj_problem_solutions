#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define abs1(x) ((x) > 0 ? (x) : (-x*i))
int main(){
  int t;cin>>t;
  while(t--){
    int n,m;
    cin>>n;
    vector<int> a(n);
    fr(i,0,n)
      cin>>a[i];
    cin>>m;
    vector<int> b(m);
    fr(i,0,m)
      cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0,j=0;
    int diff = 1000000000;
    while(i<n || j < m){
      if(a[i]<b[j]){
	if(b[j]-a[i]<diff)
	  diff = b[j]-a[i];
	if(i==n-1)
	  break;
	i++;
      }
      else if(a[i] > b[j]){
	if(a[i]-b[j] < diff)
	  diff = a[i]-b[j];
	if(j==m-1)
	  break;
	j++;
      }
      else if(a[i] == b[j]){
	diff = 0;
	break;
      }
      else
	  break;
    }
    cout<<diff<<endl;
  }
}
