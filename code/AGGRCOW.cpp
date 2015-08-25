#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
long long n,c;
vector<long long> stall;

int possible(int x){
  int placed = 1;
  long long last = stall[0];
  fr(i,1,n){
    if(stall[i] - last >= x){
      placed++;
      if(placed==c)
	return 1;
      last = stall[i];
    }
  }
  return 0;
}


int binarySearch(){
  int start = 0,end1 = stall[n-1];
  while(start<end1){
    int mid = (start+end1)/2;
    if(possible(mid))
      start = mid+1;
    else
      end1 = mid;
  }
  return start-1;
}

int main(){
  int t;cin>>t;
  while(t--){
    cin>>n>>c;
    stall.clear();stall.resize(n);
    fr(i,0,n)
      cin>>stall[i];
    sort(stall.begin(),stall.end());
    cout<<binarySearch()<<endl;
  }
}
      
    
