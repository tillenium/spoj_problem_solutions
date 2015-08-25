#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int n,k;
vector<int> arr;

int main(){
  cin>>n>>k;
  arr.resize(n);
  fr(i,0,n)
    cin>>arr[i];
  sort(arr.begin(),arr.end());
  int x = 0;int i=1;
  int count =0;
  while(x<n && i < n){
    if(x==i){
      i++;
      continue;
    }
    if(arr[i] - arr[x] == k){
      count++;i++;x++;
    }
    else if(arr[i] -arr[x] > k){
      x++;
    }
    else
      i++;
  }
  cout<<count<<endl;
}
