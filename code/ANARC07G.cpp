#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<string>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define is_integer(s) (s[0]>='0' && s[0]<='9' ? true : false)

map<string,int> m;

struct tree{
  int val;
  vector<int> child;
};

vector<string> split(string s){
  vector<string> r;
  fr(i,0,s.size()){
    string ans = "";
    int j = i;
    while(s[j]!=' ' && j<s.size()){
      ans += s[j];j++;
    }
    if(ans!="")
      r.push_back(ans);
    i = j;
  }
  return ans;
}

int to_int(string s){
  int ans = 0;
  fr(i,0,s.size()){
    ans = ans*10 + (s[i]-'0');
  }
  return ans;
}


int main(){
  string s;
  scanf("%[^\n]s",s);
  while(s[0] != '0' && s[2]!='0'){
    int single,family;
    vector<string> t = split(s);
    single = to_int(t[0]);
    family = to_int(t[1]);
    cout<<single<<" "<<family<<endl;
    int member_number = 0;
    while(scanf("%[^\n]s",s) && !is_integer(s)){
      t = split(s);
      fr(i,0,t.size()){
	
      }
    }
  }
}
