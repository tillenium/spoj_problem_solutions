#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int t;cin>>t;
  while(t--){
    double a,b,c,d,s;
    cin>>a>>b>>c>>d;
    s = (a+b+c+d);
    s /=2;
    double area = (s-a)*(s-b)*(s-c)*(s-d);
    area = pow(area,0.5);

    printf("%.2lf\n",area);
  }
}
