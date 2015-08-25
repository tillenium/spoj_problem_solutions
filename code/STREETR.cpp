#include<iostream>
#include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  int n;
  cin>>n;
    vector<int> arr(n-1);
    int c;cin>>c;
    int first = c,last;
    fr(i,0,n-1){
      int x = c;
      cin>>c;
      arr[i] = c - x;
    }
    last = c;

    int g = arr[0];
    fr(i,1,arr.size()){
      g = gcd(g,arr[i]);
    }

    cout<<(last - first + g)/g - n<<endl;
  
}

    

    
	  

    
      
