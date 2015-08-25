#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  string a,b;
  while(cin>>a>>b){
    vector<int> common(26,0);;
    vector<int> hash(26,0);
    fr(i,0,a.size())
      hash[a[i]-'a']++;

    fr(i,0,b.size()){
      if(hash[b[i]-'a']>0){
	common[b[i]-'a']++;
	hash[b[i]-'a']--;
      }
    }

    fr(i,0,26){
      while(common[i]>0)
	cout<<char(i+'a'),common[i]--;
    }
    cout<<endl;
  }
}
      
