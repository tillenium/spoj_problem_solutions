#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define br(i,a,b) for(int i=a;i>=b;i--)

int main(){
  int n;
  while(cin>>n && n){

    vector<int> arr(n);
    fr(i,0,n)
      cin>>arr[i];

    sort(arr.begin(),arr.end());
    bool possible = true;
    fr(i,1,n){
      if(arr[i] - arr[i-1] > 200){
	possible = false;
	break;
      }
    }

    if(2*(1422 - arr[n-1]) > 200)
      possible = false;

    if(possible)
      cout<<"POSSIBLE"<<endl;
    else
      cout<<"IMPOSSIBLE"<<endl;
  }
}

    
    
