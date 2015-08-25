#include<iostream>
#include<vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int e,E,f,F,s,S,m,M;
  while(true){
    cin>>e>>f>>s>>m>>E>>F>>S>>M;
    if(e<0 && E<0 && f<0 && F<0 && s<0 && S<0 && m<0 && M<0)
      break;

    while(e > 0 || f > 0 || s > 0 || m > 0){
      e -= E;
      f -= F;
      s -= S;
      m -= M;
    }
    e *= -1;
    f *= -1;
    s *= -1;
    m *= -1;

    cout<<e<<" "<<f<<" "<<s<<" "<<m<<endl;
  }
}
