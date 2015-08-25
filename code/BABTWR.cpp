#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define A first
#define B second.first
#define C second.second
#define mp(a,b,c) make_pair(a,make_pair(b,c))

typedef pair<int,pair<int,int> > iii;

int main(){
  int n;
  while(cin>>n && n){

    vector<vector<int> > box(n,vector<int> (3));

    fr(i,0,n){
      fr(j,0,3){
	cin>>box[i][j];
      }
    }

    vector<iii> arr;
    
    fr(i,0,n){
      fr(j,0,3){
	int a = box[i][j];
	int b = box[i][(j+1)%3];
	int c = box[i][(j+2)%3];
	if(a > b) swap(a,b);

	arr.push_back(mp(a,b,c));
      }
    }

    sort(arr.begin(),arr.end());


    vector<int> dp(arr.size(),0);

    dp[0] = arr[0].C;
    int ans = 0;
    fr(i,1,arr.size()){
      int h = arr[i].A;
      int l = arr[i].B;

      dp[i] = 0;

      for(int j=i-1;j>=0;j--){
	int h2 = arr[j].A;
	int l2 = arr[j].B;
	if(h2 < h && l2 < l) dp[i] = max(dp[i],dp[j]);
      }

      dp[i] += arr[i].C;
      ans = max(ans,dp[i]);
    }

    cout<<ans<<endl;
  }
}
    
    
