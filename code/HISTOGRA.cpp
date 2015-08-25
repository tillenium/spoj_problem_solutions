#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  while(cin>>n && n){
    vector<long long> h(n);
    fr(i,0,n)
      cin>>h[i];
    int i=0;
    long long m = 0;
    stack<int> s;
    while(i<n){
      if(s.empty() || h[s.top()] <= h[i]){
	s.push(i++);
      }
      else{
	int tp = s.top();s.pop();
	long long area = h[tp] * (s.empty() ? i : (i - s.top() - 1));
	if(area > m)
	  m = area;
      }
    }
    while(!s.empty()){
      int tp = s.top();s.pop();
      long long area = h[tp] * (s.empty() ? i : (i - s.top() - 1));
      if(area > m)
	m = area;
    }
    cout<<m<<endl;
  }
}
