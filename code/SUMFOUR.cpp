#include<iostream>
#include<algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define MAX 10000001

int e[MAX];
int f[MAX];
int x=0,y=0;

int binarySearch(int val){
  int size=0,mid;
  int low = 0,high=x;
  while(low<=high){
    mid = (low+high)/2;
    if(e[mid]==val){
      int temp = mid-1;
      while(mid<x && e[mid]==val){
	size++;
	mid++;
      }
      while(temp>=0 && e[temp]==val){
	size++;temp--;
      }

      return size;
    }
    else if(e[mid] > val)
      high = mid-1;
    else
      low = mid+1;
  }
  return 0;
}

int main(){
  int n;cin>>n;
  int a[n],b[n],c[n],d[n];

  fr(i,0,n){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  }

  fr(i,0,n){
    fr(j,0,n){
      e[x++] = a[i]+b[j];
      f[y++] = -1*(c[i]+d[j]);
    }
  }

  sort(e,e+x);
  sort(f,f+y);


  int count = 0;
  for(int i=0;i<y;){
    int size = 0;
    int temp = f[i];
    while(temp==f[i] && i<y){
      size++;
      i++;
    }
    
    int size2 =  binarySearch(temp);
    count += size*size2;
  }
  cout<<count<<endl;
}
