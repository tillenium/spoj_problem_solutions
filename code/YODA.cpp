#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  
  vector<long long> fact(22,1);
  char s[1000001];
  //int c[26];
  fr(i,2,21)
    fact[i] =i * fact[i-1];
  fact[21] =0;
  while(1){
    gets(s);
    if(feof(stdin)) break;
    vector<int> c(26,0);
    
    int l = strlen(s);
    int j=0;
    fr(i,0,l){
      char a = s[i];

      if(a>='a' && a<='z')
	c[a-'a']++,j++;
      else if(a>='A' && a<='Z')
	c[a-'A']++,j++;
    }

    l = 0;
    long long ways = fact[j/2];

    fr(i,0,26){
      int temp = c[i];
      l +=(temp&1);
      ways /= fact[temp>>1];
    }

    if(l>1) ways = 0;
    printf("%lld\n",ways);
  }
  
}
