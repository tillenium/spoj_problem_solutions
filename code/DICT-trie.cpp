#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define index(a) (a-'a')

struct trienode{
  char val;
  bool is_end;
  trienode *children[26];
};


void insert(trienode *&root,string word, int i){
  if(i==word.size())
    return;
  
  if(!root){
    root = new trienode;
    root->val = word[i];
    root->is_end = false;
    fr(i,0,26)
      root->children[i] = NULL;
    if(i<word.size()-1)
      insert(root->children[index(word[i+1])],word,i+1);
  }
  else{
    if(i<word.size()-1)
      insert(root->children[index(word[i+1])],word,i+1);
  }
  if(i==word.size()-1)
    root->is_end = true;
}


vector<char> output(30);
int o_index;
trienode *find_prefix_node(trienode *root, string word, int i){
  if(!root && i<word.size())
    return NULL;

  output[o_index++] = root->val;
  if(i<word.size() - 1)
    return find_prefix_node(root->children[index(word[i+1])],word,i+1);
  else
    return root;
    
}

int n,k;


void print_output(int output_index){
  fr(i,0,output_index+1)
    cout<<output[i];
  cout<<endl<<endl;
}
  
int count1;
void print_prefix(trienode *root,int output_index){
  if(!root)
    return;
  output[output_index] = root->val;
  if(root->is_end){
    print_output(output_index);
    count1++;
  }
  fr(i,0,26)
    if(root->children[i])
      print_prefix(root->children[i],output_index+1);
}



int main(){
  cin>>n;
  string s;
  trienode *head = new trienode;
  head->val = '$';
  head->is_end = false;
  fr(i,0,26)
    head->children[i] = NULL;
		   
  fr(i,0,n){
    cin>>s;
    insert(head->children[index(s[0])],s,0);
  }
  cin>>k;
  fr(i,0,k){
    cout<<"Case #"<<i+1<<":"<<endl<<endl;
    cin>>s;
    count1 = 0;
    o_index = 0;
    trienode *prefix = find_prefix_node(head->children[index(s[0])],s,0);

    if(!prefix)
      cout<<"No match."<<endl<<endl;
    else{
      fr(x,0,26){
	print_prefix(prefix->children[x],o_index);
      }
      if(!count1)
	cout<<"No match."<<endl<<endl;
    }
  }
}
    
