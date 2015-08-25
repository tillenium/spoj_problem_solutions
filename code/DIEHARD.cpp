#include<iostream>
using namespace std;

#define max(a,b) ((a) > (b) ? a : b)

int answer[2510][2510][3];

int die(int h,int a,int p){
  if(p==0){
    h += 3;
    a += 2;
  }
  else if(p==1){
    h -= 5;
    a -=10;
  }
  else{
    h -= 20;
    a += 5;
  }

  if(a < 1 || h < 1)
    return 0;
  
  if(answer[h][a][p])
    return answer[h][a][p];
  
  if(p==0)
    return answer[h][a][p] = max(die(h,a,1), die(h,a,2)) + 1;
  if(p==1)
    return answer[h][a][p] = max(die(h,a,0),die(h,a,2)) + 1;
  return answer[h][a][p] = max(die(h,a,0),die(h,a,1)) + 1;
}


int main(){
  int t,h,a;
  cin>>t;
  while(t--){
    cin>>h>>a;

    cout<<max(die(h,a,0), max(die(h,a,1),die(h,a,2)))<<endl;
  }
}
  
     
