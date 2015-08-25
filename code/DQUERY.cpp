#include<cstdio>
#include<algorithm>
using namespace std;

#define fr(i,a,b) for(int i=a;i<b;i++)
#define N 311111
#define A 1000001
#define BLOCK 555 //sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node{
  int L,R, i;
}q[200000];

bool cmp(node x,node y){
  if(x.L/BLOCK != y.L/BLOCK)
    //different blocks
    return x.L/BLOCK < y.L/BLOCK;
  return x.R < y.R;
}

void add(int p){
  cnt[a[p]]++;
  if(cnt[a[p]] == 1)
    answer++;
}

void remove(int p){
  cnt[a[p]]--;
  if(cnt[a[p]] == 0)
    answer--;
}

int main(){
  int n;
  scanf("%d",&n);
  fr(i,0,n)
    scanf("%d",&a[i]);

  int m;
  scanf("%d",&m);

  fr(i,0,m){
    scanf("%d%d",&q[i].L,&q[i].R);
    q[i].L--;q[i].R--;
    q[i].i = i;
  }

  sort(q,q+m,cmp);

  int cl = 0,cr = 0;
  fr(i,0,m){
    int l = q[i].L, r = q[i].R;

    while(cl < l){
      remove(cl);
      cl++;
    }

    while(cl > l){
      add(cl-1);
      cl--;
    }

    while(cr <= r){
      add(cr);
      cr++;
    }
    while(cr > r+1){
      remove(cr-1);
      cr--;
    }
    ans[q[i].i] = answer;
  }

  fr(i,0,m)
    printf("%d\n",ans[i]);
}

      
    

