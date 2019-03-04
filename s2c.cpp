#include <cstdio>
#include <algorithm>
#define nmax 2005
#define ub(i) i&(-i)
using namespace std;
int n,v[nmax],sol;
int a[nmax],b[nmax][nmax];
int aib[nmax][nmax],poz[nmax][nmax];


void n3()
{
    int i,j,t;
    sol=0;
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++) {
            b[i][j]=2;
            for (t=1;t<i;t++)
                if (v[j]>v[t])
                    b[i][j]=max(b[i][j],b[t][i]+1);
            sol=max(sol,b[i][j]);
        }
    printf("%d\n",sol);
}
void normalizare()
{
    int i,j,t;
    for (i=1;i<=n;i++)
        a[i]=v[i];
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++) {
        for (t=1<<10,j=1;t;t>>=1)
            if (j+t<=n&&a[j+t]<=v[i])
                j+=t;
        v[i]=j;
    }
}
int query(int i,int j)
{
    int t=0;
    for (;j;j-=ub(j))
        t=max(t,aib[i][j]);
    return t;
}
void update(int i,int j,int k)
{
    for (;j<=n;j+=ub(j))
        aib[i][j]=max(aib[i][j],k);
}
void n2lg()
{
    int i,j;
    sol=0;
    for (i=1;i<=n;i++) {
        for (j=i+1;j<=n;j++) {
            b[i][j]=max(2,query(i,v[j]-1)+1);
            sol=max(sol,b[i][j]);
        }
        for (j=i+1;j<=n;j++)
            update(j,v[i],b[i][j]);

    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            aib[i][j]=0;
    printf("%d\n",sol);

}
void n2()
{
    int i,j,t;
    for (i=1;i<=n;i++)
        a[i]=0;
    for (i=1;i<=n;i++) {
        t=1;
        for (j=1;j<=n;j++) {
            while (poz[i][t+1]&&j>=v[poz[i][t+1]])
                t++;
            if (poz[i][t])
                a[j]=t+1;
        }
        for (j=i+1;j<=n;j++) {
            b[poz[i][a[t]]][j]=a[v[j]];

        }

    }

}

int main()
{
    freopen("s2c.in","r",stdin);
    freopen("s2c.out","w",stdout);
    int t;
    for (scanf("%d",&t);t;t--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        normalizare();
            if (n<=400)
            n3();
        else {
            if (n<=1000)
            n2lg();
            else
             n2();
        }
    }
    return 0;
}
