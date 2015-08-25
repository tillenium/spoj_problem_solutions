#include <iostream>
#include <string>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

string T;
int n;
int RA[1002], tempRA[1002];
int SA[1002], tempSA[1002];
int c[1002];

void countingSort(int k){
  int i,sum,maxi = max(300,n);
  fr(i,0,1001)
    c[i] = 0;
  fr(i,0,n)
    c[i+k < n ? RA[i+k] : 0]++;

  c[0] = 0;
  sum = 0;
  fr(i,1,maxi){
    c[i] += c[i-1];
  }

  fr(i,0,n)
    tempSA[c[SA[i] + k < n ? RA[SA[i]+k] : 0]--] = SA[i];

  cout<<"new"<<endl;
  fr(i,0,n+1)
    SA[i] = tempSA[i],cout<<SA[i]<<endl;
}

void constructSA(){

  fr(i,0,n)
    RA[i] = T[i];

  fr(i,0,n)
    SA[i] = i;

  int r = 0;
  for(int k=1;k<n;(k = k<<1)){
    countingSort(k);
    countingSort(0);
    
    tempRA[SA[0]] = r = 0;

    fr(i,1,n)
      tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1]+k]) ? r : ++r;

    fr(i,0,n)
      RA[i] = tempRA[i];

    if(RA[SA[n-1]] == n-1)
      break;
  }
}


int main(){
  int each;cin>>each;
  while(each--){
    cin>>T;
    T = T + "$";
    n = T.size()-1;
    constructSA();

    fr(i,0,n)
      cout<<SA[i]<<endl;
    
  }
}
    
