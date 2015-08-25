#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int h,w,k1,t;cin>>t;
  while(t--){
  cin>>h>>w>>k1;

  vector<vector< int> > cake(h+1, vector<int> (w+1,0));
  char c;
  fr(i,1,h+1){
    fr(j,1,w+1){
      cin>>c;
      if(c=='C'){
	cake[i][j]=1+cake[i-1][j] + cake[i][j-1] - cake[i-1][j-1];
      }
      else
	cake[i][j]=cake[i-1][j] + cake[i][j-1] - cake[i-1][j-1];
    }
  }


  int mn = -1;
  int cakes = 0;
  fr(i,1,h+1)
    fr(j,1,w+1)
    fr(k,i,h+1)
    fr(l,j,w+1){
    cakes = cake[k][l];
    cakes -= cake[i-1][l];
    cakes -= cake[k][j-1];
    cakes += cake[i-1][j-1];
    if(cakes==k1){
      if(mn==-1 || mn > (l-j+1)*(k-i+1))
	mn = (l-j+1)*(k-i+1);
    }
  }

  cout<<mn<<endl;
  }
}
    

  
