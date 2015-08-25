# include<iostream>

using namespace std;

int main(){
  int t; cin>>t;
  int n;
  while(t--){
    cin>>n;
    long arr[n];
    long loc = 0;
    long increment = 0;
    for(long i=1;i<=n;i++){
      loc += increment + 1;
      arr[loc%n] = i;
      cout<<i<<endl;
      cout<<"fgdg "<<loc%n<<endl;
      increment += i+1;
    }
    for(long i=0;i<n;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
  }
}
