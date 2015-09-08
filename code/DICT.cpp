#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
int n,k;

struct tstnode{
  char data;
  tstnode *left;
  tstnode *eq;
  tstnode *right;
  bool end_of_word;
};

void insert(tstnode *&root,string word,int i){
  if(i>=word.size())
    return;
  if(!root){
    root = new tstnode;
    root->data = word[i];
    root->end_of_word = false;
    root->left = root->right = root->eq = NULL;
  }

  if(root->data > word[i]){
    insert(root->left,word,i);
  }
  else if(root->data == word[i]){
    insert(root->eq,word,i++);
  }
  else
    insert(root->right,word,i);

  if(i==word.size()-1)
    root->end_of_word = true;
        
}

vector<char> output(30);

void prefixfind(tstnode *root, string word,int i,int print_index){
  if(!root && i==word.size())
    return;
  if(!root && i>word.size())
    printword();
  if(!root)
    return;

  if(i>=word.size() || root->data > word[i]){
    output[print_index] = word[i];
    




int main(){
  cin>>n>>k;

  string s;
  tstnode *head = NULL;
  fr(i,0,n){
    cin>>s;
    insert(head,s);
  }

  
  
