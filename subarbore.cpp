#include <cstdio>
#define inf 1<<29
#define nmax 45
using namespace std;
int n,m,q,v[nmax][nmax];
int a,b,c,t;
int k[nmax],p[nmax];
int s[nmax],d[nmax];
int sol=inf;

int prim()
{
    int i,j,x,y;
    int snow=0;
    for (i=2;i<=q;i++) {
        s[i]=1;
        d[i]=v[k[1]][k[i]];
    }
    s[0]=s[q+1]=1;
    int st=2,dr=q;
    for (i=2;i<=q;i++) {
        y=inf;
        for (j=st;j<=q;j++)
            if (s[j]&&d[j]<y) {
                x=j;
                y=d[j];
            }
        snow+=y;
        for (j=2;j<=q;j++)
            if (s[j]&&v[k[x]][k[j]]<d[j])
                d[j]=v[k[x]][k[j]];
        s[x]=0;
        while (s[st]==0)
            st++;
        while (s[dr]==0)
            dr--;
    }
    return snow;
}
void backs(int r,int u)
{
    int i;
    if (r<=q) {
        int f=n-(q-r);
        for (i=u+1;i<=f;i++)
            if (p[i]==0) {
                k[r]=i;
                backs(r+1,u+1);
                k[r]=0;
        }
    }
    else {
        i=prim();
        if (i<sol)
            sol=i;
    }
}
int main()
{
    freopen("subarbore.in","r",stdin);
    freopen("subarbore.out","w",stdout);
    int i,j,t;
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (i!=j)
                v[i][j]=inf;
    for (i=1;i<=m;i++) {
        scanf("%d %d %d",&a,&b,&c);
        v[a][b]=v[b][a]=c;
    }
    for (t=1;t<=n;t++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (v[i][j]>v[i][t]+v[t][j])
                    v[i][j]=v[i][t]+v[t][j];
    scanf("%d",&t);
    q=2*t-2;
    for (i=1;i<=t;i++) {
        scanf("%d",&k[i]);
        p[k[i]]=1;
    }
    backs(t+1,0);
    printf("%d",sol);

    return 0;
}
