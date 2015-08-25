#include<iostream>
#include<queue>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;
  int n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    priority_queue<int> a;
    priority_queue<int> b;

    fr(i,0,n-1){
      int c;cin>>c;
      a.push(c);
    }
    fr(i,0,m-1){
      int c;cin>>c;
      b.push(c);
    }

    int x = 1,y = 1;
    long long  cost = 0;
    while(x<n || y < m){
      if(x<n && y<m){
	if(a.top() > b.top()){
	  cost += a.top() * y;
	  a.pop();
	  x++;
	}
	else{
	  cost += b.top() * x;
	  b.pop();
	  y++;
	}
      }
      else if(x<n){
	cost += a.top() * y;
	a.pop();
	x++;
      }
      else{
	cost += b.top() * x;
	b.pop();
	y++;
      }
    }

    cout<<cost<<endl;
  }
}
    
