#include <iostream>
#include <vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int binary( vector<int> A , int l , int r , int key )
{
  int m ;

  while( r - l > 1 )
    {
      m = l + ( r - l ) / 2 ;
      ( A[m] >= key ? r : l) = m ;
    }

  return r ;
}



int main(){
  int t;
  int n;
  cin>>t;
  while(t--){
    cin>>n;
    vector<int> v(n);
    vector<int> m(n);

    fr(i,0,n){
      int temp;
      cin>>temp;
      temp--;
      v[temp] = i;
    }
    vector<int> l;
    int ans = 0;
    fr(i,0,n){
      cin>>m[i];
      m[i]--;
      m[i] = v[m[i]];
    }

    l.push_back(m[0]);
    fr(i,1,n){
      int num = m[i];
      if(num < l[0])
	l[0] = num;
      else if(l[l.size()-1]<num)
	l.push_back(num);
      else{
	l[binary(l,-1,l.size(),num)] = num;
      }
    }
    cout<<l.size()<<endl;

    
  }
}

    
