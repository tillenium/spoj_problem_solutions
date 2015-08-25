#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define min(a,b) ((a) > (b) ? (b) : (a))

vector<int> mem;
string  s,t;

int edit(int i,int j){
  if(i==s.size())
    return (mem[i] = t.size() - i);
  int a=1000000000;
  int b = 1000000000;
  if(mem[i]!=-1)
    return mem[i];
  if(s[i]==t[j])
    a = edit(i+1,j+1);
  return (mem[i] = min(min(edit(i+1,j)+1,a), edit(i+1,j+1)+1));
}
	  

int main(){
  int t1;cin>>t1;
  while(t1--){
    cin>>s>>t;

    if(s.size() > t.size()){
      string temp = s;
      s = t;
      t = temp;
    }
    mem.clear();mem.resize(s.size()+1,-1);
    cout<<edit(0,0)<<endl;
    fr(i,0,s.size()+1)
      cout<<mem[i]<<endl;
  }
}
