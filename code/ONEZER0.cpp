#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;


struct node{
  int value;
  int rem;
  node *parent;
};

node *bfs(int num){
  queue<node*> q;

  //map<string,bool> visited;
  node *n = new node;n->value = 1;n->parent = NULL;n->rem = 0;
  q.push(n);
  int r = 0;
  node *v;
  while(!q.empty()){
    v = q.front(); q.pop();
    if(v->value==0)
      r = (10*v->rem + 0)%num;
    else
      r = (10*v->rem + 1)%num;
    if(r==0)
      return v;
    node *t = new node;t->value = 0;t->rem = r; t->parent=v;
    q.push(t);
    node *u = new node;u->value = 1;u->rem = r; u->parent=v;
    q.push(u);
  }
  return n;
}

void printPath(node *n){
  if(n==NULL)
    return;
  printPath(n->parent);
  cout<<n->value;
}

int main(){
  int t;cin>>t;
  int n;
  while(t--){
    cin>>n;
    node *ans = bfs(n);
    printPath(ans);
    cout<<endl;
  }
}

