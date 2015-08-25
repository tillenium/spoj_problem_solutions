#include <iostream>
#include <vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)

vector<int> preorder;
vector<int> postorder;
vector<int> inorder;

int search(int start,int end, int num){
  fr(i,start,end+1)
    if(inorder[i]==num)
      return i;
  return -1;
}

int pre = 0;
int post = 0;
bool treePre(int start,int end){
  if(start>end)
    return true;
  //cout<<"i: "<<i<<endl;
  //tree[i] = preorder[pre];
  int index = search(start,end,preorder[pre]);
  pre++;
  bool left = treePre(start,index-1);
  bool right = treePre(index+1,end);
  if(!left || !right)
    return false;
  return (inorder[index] == postorder[post++]);
}

int main(){
  int n;cin>>n;
  int c;
  preorder.resize(n,0);
  postorder.resize(n,0);
  inorder.resize(n,0);
  fr(i,0,n)
    cin>>preorder[i];
  fr(i,0,n)
    cin>>postorder[i];
  fr(i,0,n)
    cin>>inorder[i];

  cout<<(treePre(0,n-1) ? "yes" : "no");
}
