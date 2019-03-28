#include <cstdio>
#define nmax 100005
using namespace std;
int n,v[nmax],s[nmax],a,b,ans=-1;
struct trie{
    int val,ord;trie *son[2];
    trie() {son[0]=son[1]=0;};};
trie *t=new trie;
trie *p;


trie * searchtrie(trie *t,int val,int pos)
{
    if (pos<0)
        return t;
    int i=((val&(1<<pos))!=0);
    if (t->son[0]==0&&t->son[1]==0)
        return 0;
    if (t->son[1-i])
        return searchtrie(t->son[1-i],val,pos-1);
    return searchtrie(t->son[i],val,pos-1);
}
void addtrie(trie *t,int val,int ord,int pos)
{

    if (pos<0) {
        t->val=val;
        t->ord=ord;
        return;
    }
    int i=((val&(1<<pos))!=0);
    if (!t->son[i]) {
        trie *k=new trie;
        t->son[i]=k;
    }
    addtrie(t->son[i],val,ord,--pos);
}
int xoring(int i,int j)
{
    int k=0;
    for (int bit=1<<22;bit;bit>>=1)
        k+=bit*((((i&bit)!=0)+((j&bit)!=0))%2);
    return k;
}
int main()
{
    int i,j;
    freopen("xormax.in","r",stdin);
    freopen("xormax.out","w",stdout);
    scanf("%d",&n);
    addtrie(t,0,0,22);
    for (i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        s[i]=s[i-1]^v[i];
        p=searchtrie(t,s[i],22);
        j=xoring(p->val,s[i]);
        if (j>ans) {
            ans=j;
            a=(p->ord)+1;
            b=i;
        }
        addtrie(t,s[i],i,22);
    }
    printf("%d %d %d",ans,a,b);
    return 0;
}
