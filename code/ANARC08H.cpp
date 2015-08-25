#include<iostream>

using namespace std;

int main(){
  int n,k;
  while(cin>>n && cin>>k && (n || k)){
    long long ans = 1;
    for(int i=2;i<=n;i++){
      ans = (ans + k - 1) % i + 1;
    }
    
    cout<<n<<" "<<k<<" "<<ans<<endl;
  }
}
	 
