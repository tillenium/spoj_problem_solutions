#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  vector<int> friend1(10000,0);

  cin>>n;
  int c,m;
  int ff = 0;
  fr(i,0,n){
    cin>>c;
    if(friend1[c]==2)
      ff--;
    friend1[c] =1;
    cin>>m;
    
    fr(j,0,m){
      cin>>c;
      if(friend1[c]==0){
	ff++;

	friend1[c] = 2;
      }
    }

   
  }
   cout<<ff;
}
