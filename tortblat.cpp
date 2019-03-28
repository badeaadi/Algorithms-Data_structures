#include <cstdio>
#include <algorithm>
#include <fstream>
#define nmax 505
using namespace std;
char s[nmax][nmax];
int n,m,k,v[nmax][nmax];
int p[nmax][nmax],cont;

struct sols{int k;int l;int c;};
sols sol[nmax];

bool solcomp(const sols &a,const sols &b)
{
    if (a.k!=b.k)
        return a.k>b.k;
    if (a.l!=b.l)
        return a.l<b.l;
    return a.c<b.c;
}
ofstream g("tort.out");
int main()
{
    int i,j,t,l,c;
    freopen("tort.in","r",stdin);
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++) {
        scanf("%s",&s[i]);
        for (j=1;j<=m;j++)
            v[i][j]=s[i][j-1]-'0';
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (!p[i][j]) {
                l=i;c=j;
                do
                {
                    l++,c++;
                    cont=1;
                    for (t=j;t<=c;t++)
                        if (v[l][t]!=v[i][j]) {
                            cont=0;
                            break;
                        }
                    for (t=i;t<=l;t++)
                        if (v[t][c]!=v[i][j]) {
                            cont=0;
                            break;
                        }
                } while (i<=n&&j<=m&&cont);

                l--;c--;
                k++;
                sol[k].k=l-i+1;
                sol[k].l=l;
                sol[k].c=c;



                for (;l>=i;l--)
                    for (t=c;t>=j;t--)
                        p[l][t]=1;

            }
    sort(sol+1,sol+k+1,solcomp);

    for (i=1;i<=k;i++)
        g<<sol[i].k<<' '<<sol[i].l<<' '<<sol[i].c<<'\n';

    return 0;
}
