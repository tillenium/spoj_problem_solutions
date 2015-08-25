#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

#define p(a) printf("%d",&a);
#define s(a) scanf("%d",a);
int multiply(char a,char b){
  int x = a - '0';
  int y = b - '0';
  return x*y;
}

int main(){
  int t;
  string a,b;cin>>t;
  while(t--){
    cin>>a>>b;
    if(a.size() < b.size()){
      string temp = a;
      a = b;
      b = temp;
    }
      
    vector<vector<int> > mul(b.size(),vector<int> (a.size() + b.size() + 1,0));
    int r = 0;
    int c = 0;
    for(int i = b.size()-1;i>=0;i--){
      c = mul[i].size() - 1 - (b.size() - 1 - i);
      for(int j = a.size()-1;j>=0;j--){
	int m = multiply(a[j],b[i]) + mul[r][c];
	mul[r][c] = (m%10);c--;
	mul[r][c] += m/10;
      }
      r++;
    }
    int sum = 0;
    int carry = 0;

    for(int j=mul[0].size()-1;j>=0;j--){
      sum = 0;  
      for(int i=0;i<mul.size();i++)
	sum += mul[i][j];
      
      mul[mul.size()-1][j] = (carry+sum)%10;
      carry = (carry + sum)/10;
    }

    //    for(int i=0;i<mul[0].size();i++)
    //cout<<mul[mul.size()-1][i]<<" ";

    int i = 0;
    while( i< mul[0].size()-1 && mul[mul.size()-1][i]==0)i++;
    while(i< mul[0].size())
      cout<<mul[mul.size()-1][i++];
    cout<<endl;
  }
    
}
  
