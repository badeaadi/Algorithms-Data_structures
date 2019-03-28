#include <cstdio>
#define nmax 100005
#define dmax 10005
using namespace std;
int n,m,k,p,a[nmax],b[nmax],c[nmax];
int v[dmax][dmax],s[dmax][dmax];
int sol[dmax][dmax];

int sum(int k[],int c1,int c2)
{
    return k[c2]-k[c1-1];
}
void adding(int k[],int c1,int c2)
{
    for (int i=c1;i<=c2;i++)
        k[i]=1;
}
void solvetest()
{
    int i,j;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d",&p);
    for (i=1;i<=p;i++) {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        for (j=a[i];j<=b[i];j++)
            v[c[i]][j]=1;
    }
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++)
            s[i][j]=v[i][j]+s[i][j-1];
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            if (sum(s[i-1],j,j+k-1)+sum(s[i],j,j+k-1)+sum(s[i+1],j,j+k-1)==3*k) {
                adding(sol[i-1],j,j+k-1);
                adding(sol[i],j,j+k-1);
                adding(sol[i+1],j,j+k-1);
            }
        }
}
int main()
{
    freopen("wildfire.in","r",stdin);
    freopen("wildfire.out","w",stdout);
    int t;
    for (scanf("%d",&t);t;t--)
        solvetest();
}
