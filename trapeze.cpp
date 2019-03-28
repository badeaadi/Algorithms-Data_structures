#include <cstdio>
#include <vector>
#define cmax 1005
#define kmax 205
using namespace std;
int d[kmax][kmax],aux[kmax];
int c[cmax];
vector <int> v;

void erath()
{
    int i,j;
    for (i=2;i<cmax;i++)
        c[i]=i;
    for (i=2;i*i<cmax;i++)
        if (c[i])
            for (j=i*i;j<cmax;j+=i)
                c[j]=0;
    for (i=3;i<cmax;i++)
        if (c[i])
            v.push_back(i);
}
void copyy(int a[],int b[])
{
    int i;
    for (i=1;i<=a[0];i++)
        a[i]=0;
    a[0]=0;

    for (i=0;i<=b[0];i++)
        a[i]=b[i];
}
void prod(int a[],int x)
{
    int i;
    for (i=1;i<=a[0];i++)
        a[i]*=x;
    for (i=1;i<a[0];i++)
        if (a[i]>9) {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    while (a[a[0]]) {
        a[a[0]+1]+=a[a[0]]/10;
        a[a[0]]%=10;
        a[0]++;
    }
    a[0]--;
}
int comp(int a[],int b[])
{
    if (a[0]>b[0])
        return 1;
    if (a[0]<b[0])
        return 0;
    int i=a[0];
    while (i>=1&&a[i]==b[i])
        i--;
    if (a[i]>b[i])
        return 1;
    return 0;
}
void verifyy(int a[],int b[])
{
    int i;
    if (comp(a,b))
        copyy(a,b);
}
int main()
{
    freopen("trapeze.in","r",stdin);
    freopen("trapeze.out","w",stdout);
    int i,j,t,p,k;
    erath();
    scanf("%d",&k);
    d[1][0]=d[1][1]=1;
    for (i=2;i<=k;i++) {
        d[i][0]=d[i][1]=1;
        for (j=1;j<=15;j++)
            prod(d[i],1<<20);
    }
    for (i=0;i<v.size();i++) {
        p=v[i];
        for (j=k;j>=1;j--) {
                copyy(aux,d[j]);
                for (t=1;j*(t+1)<=k;t++) {
                    prod(aux,p);
                    verifyy(d[j*(t+1)],aux);
                }
            }
    }
    for (i=d[k][0];i>=1;i--)
        printf("%d",d[k][i]);
    return 0;
}
