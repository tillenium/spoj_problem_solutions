#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define val(a) (a-'a')

struct trie{
  bool is_end;
  trie *children[26];
};

void insert(trie *&root,char *word,int i){
  if(i==strlen(word))
    return;

  if(!root){
    root = new trie;
    fr(i,0,26){
      root->children[i] = NULL;
    }
  }
  if(i<strlen(word)-1)
    insert(root->children[val(word[i+1])],word,i+1);
  else
    root->is_end = true;
}

char output[25];
bool exists;
void print_output(int index){
  exists = true;
  fr(i,0,index)
    printf("%c",output[i]);
  printf("\n");
}

void dfs(trie *root,int oi){
  if(!root)
    return;

  if(root->is_end)
    print_output(oi);
  
  fr(i,0,26){
    if(root->children[i]){
      output[oi] = i+'a';
      dfs(root->children[i],oi+1);
    }
  }
  
}


trie *prefix_end(trie *root,char *word,int i){
  if(!root)
    return NULL;
  if(i<strlen(word)-1)
    return prefix_end(root->children[val(word[i+1])],word,i+1);
  return root;
}


int main(){
  int n,k;
  char s[30];
  scanf("%d",&n);
  trie *head = new trie;
  fr(i,0,26)
    head->children[i] = NULL;
  
  while(n--){
    scanf("%s",s);
    insert(head->children[val(s[0])],s,0);
  }
  scanf("%d",&k);
  fr(i,1,k+1){
    scanf("%s",s);
    exists = false;
    cout<<"Case #"<<i<<":\n";
    trie *prefix = prefix_end(head->children[val(s[0])],s,0);
    if(!prefix)
      cout<<"No match.\n"<<endl;
    else{
      int in = 0;
      fr(x,0,strlen(s))
	output[in++] = s[x];
      fr(x,0,26){
	if(prefix->children[x]){
	  output[in] = x + 'a';
	  dfs(prefix->children[x],in+1);
	}
      }
      if(!exists)
	cout<<"No match.\n"<<endl;
    }

  }
  
}
    
