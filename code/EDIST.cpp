#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) < (b) ? a : b)
int main(){
  int t;cin>>t;
  string a,b;
  while(t--){
    cin>>a>>b;

    vector< vector<int> > c(a.size()+1,vector<int> (b.size()+1,0));

    fr(j,0,b.size()+1){
      c[0][j] = j;
    }
    
    fr(i,1,a.size()+1){
      c[i][0] = i;
      fr(j,1,b.size()+1){
	if(a[i-1]==b[j-1])
	  c[i][j] = min(c[i-1][j]+1,min(c[i][j-1]+1,c[i-1][j-1]));
	else
	  c[i][j] = min(c[i-1][j]+1,min(c[i][j-1]+1,c[i-1][j-1]+1));

      }
    }
    cout<<c[a.size()][b.size()]<<endl;
  }
}
      
      
