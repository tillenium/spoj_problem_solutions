#include<iostream>

using namespace std;

int main(){
  long number;

  int bitset[2,147,483,648];
  for(int i=1;i<=2,147,483,647;i++)
    bitset[i] = 0;
  for(int i=0;i<32;i++){
    cin>>number;
    long steps = 0;
    while(number>9){
      long n = number;
      number = 0;
      while(n>0){
	number += (n%10) * (n%10);
	n = n/10;
      }
      steps++;
    }
    if (number ==1 || number ==3 || number ==7){
      while(true){
	if(number==1)
	  break;
	long n = number;
	number = 0;
	while(n>0){
	  number +=( n%10) *(n%10);
	  n = n/10;
	}
	
	steps++;
      }
    cout<<steps<<endl;
  }
  else{
    cout<<-1<<endl;
  }
}
}
