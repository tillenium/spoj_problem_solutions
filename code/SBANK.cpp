#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<string> bank(n);
    fr(i,0,n){
      string s;
      fr(j,0,6){
	string c;cin>>c;
	s +=(c + " ");
      }
      bank[i] = s;
    }
    sort(bank.begin(),bank.end());
    string a = bank[0];
    int x = 1;
    fr(i,1,n){
      if(bank[i]==a)
	x++;
      else{
	cout<<a<<x<<endl;
	a = bank[i];
	x = 1;
      } 
    }
    cout<<a<<x<<endl;
  }
}
      
