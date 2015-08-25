#include<iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int si(int s){
  return  (78901 + 31*s)% 699037;
}

int ti(int t){
  return (23456 + 64*t)%2097151;
}

int ai(int s,int t){
  return (s%100 + 1) * (t%100 + 1);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int s,t,n,m;
    cin>>s>>t>>n>>m;
    int a;
    int i=0;
    int sum = 0;
    vector<int> A;
    while(i!=n){
      s = si(s);t = ti(t);a=ai(s,t);
      A.push_back(a);
      i++;
    }
    i = 0;
    int j=0;
    int k=0;
    while(k<=m && j<n){
      k += A[j++];
    }
    while(i<=j && j<n){
      while(k>m){
	k -= A[i++];
      }
      k = k + A[j++] - A[i++];
    }
    cout<<j-i<<endl;
  }
}
	    
