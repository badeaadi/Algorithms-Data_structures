#include <cstdio>
#include <cstring>
#define teta 26
#define pmax 32
#define mmax 30005
int n,k,m,p,q,z[pmax];
char v[mmax][pmax];
char r[pmax][pmax],s[pmax*pmax];

struct trie{
    trie * son[teta];
    int cnt;
    trie() {
        memset(son,0,sizeof(son));
        cnt=0;
    };};
trie *t=new trie;


void addtrie(trie *t,char *p)
{
    if (!p[0])
        return;
    t->cnt++;
    if (!(t->son[p[0]-'a'])) {
        trie *w=new trie;
        t->son[p[0]-'a']=w;
    }
    addtrie(t->son[p[0]-'a'],p+1);
}
int searchtrie(trie *t,char *s,int a)
{
    if (a>p*k)
        return 0;
    for (int i=0;i<a;i++) {
        if (!(t->son[s[i]-'a']))
            return 0;
        t=t->son[s[i]-'a'];
    }
    return t->cnt;
}
int main()
{
    int i,j,o,l,x;
    freopen("sabin.in","r",stdin);
    freopen("sabin.out","w",stdout);
    scanf("%d %d %d %d %d\n",&n,&k,&m,&p,&q);
    for (i=1;i<=n;i++) {
        for (j=1;j<=k;j++) {
            memset(r[j],0,sizeof(r[j]));
            scanf("%s\n",&r[j]);
        }
        memset(s,0,sizeof(s));
        for (j=0,l=-1;j<p;j++)
            for (o=1;o<=k;o++)
                s[++l]=r[o][j];
        addtrie(t,s);
    }
    for (i=1;i<=m;i++)
        scanf("%s",&v[i]);
    for (i=1;i<=q;i++) {
        scanf("%d",&x);
        for (j=1;j<=k;j++)
            scanf("%d",&z[j]);
        memset(s,0,sizeof(s));
        for (j=0,l=-1;j<p;j++)
            for (o=1;o<=k;o++)
                s[++l]=v[z[o]][j];

        printf("%d\n",searchtrie(t,s,k*x)-searchtrie(t,s,k*(x+1)));
    }
    return 0;
}
