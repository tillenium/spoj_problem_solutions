# include<iostream>
# include<string>
# include<vector>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))

int leastCommonSubstring(string a,string b){
  vector<vector<int> >lcs(1+a.size(), vector<int>(b.size()+1,0));

  int result = 0;

  fr(i,0,a.size()+1){
    fr(j,0,b.size()+1){
      if(i==0 || j==0)
	lcs[i][j]=0;
      else if(a[i-1]==b[j-1]){
	lcs[i][j] = lcs[i-1][j-1] + 1;
	result = max(result,lcs[i][j]);
      }
      else
	lcs[i][j] = 0;
    }
  }
  return result;
}
  
  

int main(){
  int t;cin>>t;
  string a,b;
  while(t--){
    cin>>a>>b;
    if(a.size()>b.size()){
	string temp = a;
	a = b;
	b = temp;
      }
    cout<<b.size()-leastCommonSubstring(a,b)<<endl;
  }
}
    
  
