#include<iostream>
using namespace std;

#define min(a,b) ((a) > (b) ? b : a)


int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int pour(int A,int B,int C){
  int move = 1,a=A,b=0,tfr;
  while(a!=C && b!=C){
    tfr = min(a,B-b);
    b += tfr;
    a -= tfr;
    move++;

    if(a==C || b==C)
      break;
    if(a==0){
      a = A;
      move++;
    }
    if(b==B){
      b=0;
      move++;
    }
  }
  return move;
}

int main(){
  int t;cin>>t;
  while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    if(c>a && c>b)
      cout<<-1<<endl;
    else if(c%gcd(a,b)!=0)
      cout<<-1<<endl;
    else{
      cout<<min(pour(a,b,c),pour(b,a,c))<<endl;
    }
  }
}
