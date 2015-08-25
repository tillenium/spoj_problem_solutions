#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n,m;
  while(cin>>n && n){
    // cin>>m;

    vector<int> a(n);
    //vector<int> b(m);

    vector<int> hash(20001,-1);

    fr(i,0,n){
      int c;
      cin>>c;
      hash[c+10000]=i;
      a[i] = c;
      //cout<<hash[c+1000]<<endl;
    }
    int total = 0;
    int j = 0;
    int x=0,y=0;
    //cout<<"hwer"<<endl;
    cin>>m;
    fr(i,0,m){
      int c;cin>>c;
      
      if(hash[c+10000]!=-1){
	y = 0;
	fr(k,j,hash[c+10000])
	  y += a[k];

	total += max(x,y) + c;
	x = 0;
	j = hash[c+10000]+1;
      }
      else{
	x += c;
      }
    }
    y = 0;
    fr(k,j,n)
      y += a[k];
    total += max(x,y);
    cout<<total<<endl;
  }
}
