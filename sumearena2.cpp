#include <cstdio>
#include <algorithm>
#include <fstream>
#define nmax 50005
using namespace std;
FILE *f=fopen("sume2.in","r");
FILE *g=fopen("sume2.out","w");
int n,v[nmax];
char cnt[nmax*40];
long long k;

inline int cautbin(int p,int q,int x)
{
    int sol,mijl;
    while (p<=q) {
        mijl=(p+q)>>1;
        if (x>v[mijl]) {
            sol=mijl;
            p=mijl+1;
        }
        else
            q=mijl-1;
    }
    return sol;
}
int exist(int x)
{
    int i;
    for (i=1;i<=n;i++)
        if (x>=v[i]&&cnt[x-v[i]]==1)
            return 1;
    return 0;
}
int solve()
{
    int i,pos,sol,caut;
    long long tot;
    int mijl,st=0,dr=v[n]<<1;
    while (st<=dr) {
        mijl=(st+dr)>>1;
        tot=0;
        for (i=1;i<=n;i++) {
            caut=mijl-v[i];
            if (caut>=0) {
                pos=cautbin(0,n,caut);
                tot+=pos;
            }
        }
        if (tot<k) {
            sol=mijl;
            st=mijl+1;
        }
        else
            dr=mijl-1;
    }
    return sol;
}


int main()
{
    int i,j;
    fscanf(f,"%d %lld",&n,&k);
    for (i=1;i<=n;i++) {
        fscanf(f,"%d",&v[i]);
        cnt[v[i]]=1;
    }
    sort(v+1,v+n+1);
    i=solve();
    while (exist(i)==0)
        i++;

    fprintf(g,"%d\n",i);
    return 0;
}
