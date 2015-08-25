#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
int main(){
  int t;cin>>t;
  while(t--){
    vector<int> girl;
    int n;
    while(cin>>n && n){
      girl.push_back(n);
    }
    int m =-1;
    while(1){
      vector<int> boy;
      
      while(cin>>n && n){
	boy.push_back(n);
      }

      if(boy.size()==0)
	break;
      
      vector<vector<int> > lcs(girl.size()+1,vector<int> (boy.size()+1,0));

      fr(i,1,girl.size()+1){
	fr(j,1,boy.size()+1){
	  if(girl[i-1]==boy[j-1])
	    lcs[i][j] = 1 + lcs[i-1][j-1];
	  else
	    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
	}
      }
      if(lcs[girl.size()][boy.size()]>m)
	m = lcs[girl.size()][boy.size()];
    }
    cout<<m<<endl;
  }
}
