#include<iostream>
#include<vector>
#include<queue>
#include <string>
using namespace std;

#define num first
#define sum second.first
#define ans second.second
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mp(a,b,c) (make_pair(a, make_pair(b,c)))

typedef pair<int , pair<int, string> > iis;

int n;

bool divisible(vector<int> v){
  int s = 0;
  fr(i,0,v.size()){
    s = (s*10 + v[i])%n;
  }
  return s==0;
}

string bfs(){
  queue<iis> q;
  //vector<vector<int > > number(10,vector<int> (500,0));
  fr(i,1,10){
    //number[i][0] = i;
    string s = "";
    char c = '0'+i;
    s +=c;
    //cout<<c<<": "<<i<<endl;
    q.push(mp(i%n,i,s));
  }
  //int i=-1;
  //int j=0;
  //int k=-1;
  //int level = 10;
  while(!q.empty()){
    iis c = q.front();q.pop();
    //if(j%(level/10)==0)
    //  k++;
    //if(j==0){
    //   i++;
    //   level *= 10;
    //}
    //j = (j+1)%level;
    //number[k][i] = c.
    //cout<<c.ans<<endl;
    if(c.sum==n && c.num==0)
      return c.ans;
      fr(i,0,10){
	char cc = '0'+i;
	if(c.sum+i<=n)
	  q.push(mp((c.num*10+i)%n,c.sum+i,c.ans+cc));
      }
  }
  return "";
}

int main(){
  int t;cin>>t;
  while(t--){
    cin>>n;
    cout<<bfs();
  }
}

    
      
