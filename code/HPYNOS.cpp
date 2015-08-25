#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> num(1000,0);
  int ans = 0;
  while(n!=1){
    int next = 0;
    while(n!=0){
      next += (n%10)*(n%10);
      n /= 10;
    }
    if(num[next])
      break;
    else
      num[next] = 1;
    n = next;
    ans++;
  }

  if(n==1)
    cout<<ans;
  else
    cout<<-1;
}
