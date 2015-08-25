#include<iostream>
#include<vector>
using namespace std;
int main(){int t,n;cin>>t;while(t--){cin>>n;vector<int> a(n+1,0);int c;int m=0;for(int i=1;i<=n;i++) for(int j=i;j>=1;j--){cin>>c;a[j]=c+max(a[j],a[j-1]);if(a[j] > m) m = a[j];}cout<<m<<endl;}}
