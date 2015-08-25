#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  vector<int> numbers(1000001,1);
  fr(i,2,101){
    int c = i*i*i;
    if(numbers[c]){
      for(int j=c;j<1000001;j += c)
	numbers[j] = 0;
    }
  }
  int index = 1;
  fr(i,1,1000001)
    if(numbers[i])
      numbers[i] = index++;
      

  int t,n;cin>>t;
  index = 1;
  while(t--){
    cin>>n;
    cout<<"Case "<<index++<<": ";
    if(numbers[n])
      cout<<numbers[n]<<endl;
    else
      cout<<"Not Cube Free"<<endl;
  }
}
