#include<iostream>
#include<algorithm>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
  int n;
  cin>>n;
  int a[n];
  fr(i,0,n)
    cin>>a[i];
  //sort(a,a+n);

  int l=0,lhs[n*n*n],r=0,rhs[n*n*n];

  fr(i,0,n){
    fr(j,0,n){
      fr(k,0,n){
	lhs[l++] = a[i]*a[j] + a[k];
      }
    }
  }

  fr(i,0,n){
    if(a[i]!=0)
      fr(j,0,n){
	fr(k,0,n){
	  rhs[r++] = a[i]*(a[j] + a[k]);
	}
      }
  }

  sort(lhs,lhs+l);sort(rhs,rhs+r);

  int ans = 0;
  int left = 0;
  fr(i,0,l){
    
    left = 1;
    while(i!=l-1 && lhs[i]==lhs[i+1])
      left++,i++;



    int start=0,end=r-1,right=0;
    while(start<=end){
      int mid=(end+start)/2;

      if(rhs[mid] < lhs[i])
	start = mid+1;
      else if(rhs[mid] > lhs[i])
	end = mid-1;
      else{
	right++;
	int k=mid+1;
	while(k!=r  && rhs[k++]==lhs[i])
	  right++;
	k = mid-1;
	while(k>=0 && rhs[k--]==lhs[i])
	  right++;
	break;
      }
    }

    ans += left*right;
  }
  cout<<ans;
}






	  
