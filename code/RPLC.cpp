#include<iostream>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int t;cin>>t;
  fr(ca,1,t+1){
    int n;
    cin>>n;
    long long num = 0;
    long long  m = 0;
    long long c;
    fr(i,0,n){
      cin>>c;
      num += c;
      if(num < m && num<0)
	m = num;
    }
     m = -1*m;
     cout<<"Scenario #"<<ca<<": "<<m+1<<endl;
  }
}
