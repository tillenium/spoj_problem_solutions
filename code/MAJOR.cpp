#include <iostream>
#include <vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
     int t; cin>>t;
     while(t--){
       int n;cin>>n;
       vector<int> hash(2001,0);

       int maxnum = -1;

       fr(i,0,n){
	 int a;cin>>a;
	 hash[a+1000]++;
	 if(hash[a+1000]>(n+1)/2)
	   if(maxnum==-1 || hash[maxnum+1000]<hash[a+1000])
	     maxnum = a;
       }
       
       if(maxnum!=-1)
	 cout<<"YES "<<maxnum<<endl<<endl;
       else
	 cout<<"NO"<<endl<<endl;
     }
}
	    
       
