#include <cstdio>
#include <fstream>
#include <algorithm>
#define nmax 55
#define inf 2000000000
using namespace std;
long long v[50],aux;
int p,n,k,a[nmax];


void solveone()
{
    int i;
    v[1]=a[1];v[2]=a[1];
    for (i=3;i<=k;i++)
        v[i]=1LL+v[i-1]+v[i-2]-1;
    for (i=1;i<=k;i++)
        printf("%d ",v[i]);}
void solvesecond()
{
    bool ok;
    int i,j,t;
    for (i=1;i<=n;i++)
        v[i]=a[i];
    while (n<k) {
        v[++n]=v[n-1]+v[n-2];
        if (v[n]>inf) {
            v[n--]=0;
            break;
        }
    }
    i=1;
    j=1;
    while (n<k&&i<=100000) {
        ok=true;
        while (j<n&&v[j]+v[j+1]<=i)
            j++;
        if (j<n&&v[j]+v[j+1]>i&&i+v[j]>v[j+1])
            ok=false;
        if (j+1<n&&v[j+1]+v[j+2]>i&&i+v[j+1]>v[j+2])
            ok=false;
        if (ok==true) {
            v[++n]=i;
            j=n;
            while (j>=1&&v[j-1]>v[j]) {
                aux=v[j];
                v[j]=v[j-1];
                v[j-1]=aux;
                j--;
            }
        i--;
        j--;
        }
    i++;
    }


    i=1;t=1;
    j=1;
    while (n<k) {
        ok=true;
        while (j<n&&v[j]+v[j+1]<=i)
            j++;
        if (j<n&&v[j]+v[j+1]>i&&i+v[j]>v[j+1])
            ok=false;
        if (j+1<n&&v[j+1]+v[j+2]>i&&i+v[j+1]>v[j+2])
            ok=false;
        if (ok==true) {
            v[++n]=i;
            j=n;
            while (j>=1&&v[j-1]>v[j]) {
                aux=v[j];
                v[j]=v[j-1];
                v[j-1]=aux;
                j--;
            }
        t--;
        j--;
        }
    t++;
    i=v[t]+v[t+1];
    }
    for (i=1;i<=k;i++)
        printf("%d ",v[i]);
}
int main()
{
    freopen("triunghi5.in","r",stdin);
    freopen("triunghi5.out","w",stdout);
    int i;
    scanf("%d %d %d\n",&p,&n,&k);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if (p==1)
        solveone();
    else
        solvesecond();

return 0;
}
