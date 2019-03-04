#include <bits/stdc++.h>
#define nmax 20
#define lmax 30005
#define inf 1<<29
using namespace std;
char s[nmax][lmax],o[lmax];
char af[nmax*lmax];
int n,v[(1<<18)+50][nmax];
short q[(1<<18)+50][nmax];
int cost[nmax][nmax],com[nmax][nmax],t[nmax];
int pi[lmax],a[nmax];
int sol,soli,solj,poz[nmax],cnt[nmax],soll;


int main()
{
    int i,j,l,k,p;
    freopen("adn.in","r",stdin);
    freopen("adn.out","w",stdout);
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        memset(o,0,sizeof(o));
        scanf("%s",&o);
        memcpy(s[i]+1,o,lmax);
        while (s[i][t[i]+1])
            t[i]++;
    }
    for (i=0;i<n;i++) {
        pi[1]=0;
        a[i]=1;
        for (k=2,l=0;s[i][k];k++) {
            while (l&&s[i][k]!=s[i][l+1])
                l=pi[l];
            if (s[i][k]==s[i][l+1])
                l++;
            pi[k]=l;
        }
        for (j=0;j<n&&a[i];j++)
            if (i!=j) {
                for (k=1,l=0;s[j][k]&&a[i];k++) {
                    while (l&&s[j][k]!=s[i][l+1])
                        l=pi[l];
                    if (s[j][k]==s[i][l+1])
                        l++;
                    if (l==t[i]) {
                        if (l==t[j])
                            a[min(i,j)]=0;
                        else
                            a[i]=0;
                    }
                }

                com[j][i]=l;
                cost[j][i]=t[i]-com[j][i];
            }
    }
    for (i=0;i<n;i++)
        if (a[i]) {
            v[1<<i][i]=t[i];
            soli+=1<<i;
        }
    for (i=0;i<(1<<n);i++)
        for (j=0;j<n;j++)
            if (!v[i][j])
                v[i][j]=inf;
    for (i=0;!a[i];i++);
    for (i=1<<i;i<soli;i++)
        for (j=0;j<n;j++)
            if (a[j])
            if ((i&(1<<j))==0) {
                p=i+(1<<j);
                for (k=0;k<n;k++)
                    if (a[k]&&v[i][k]!=inf)
                    if (i&(1<<k))
                        if (v[i][k]+cost[k][j]<v[p][j]) {
                            v[p][j]=v[i][k]+cost[k][j];
                            q[p][j]=k;
                        }
            }
    sol=inf;
    for (i=0;i<n;i++)
        if (v[soli][i]<sol) {
            sol=v[soli][i];
            solj=i;
        }
    int m=0;
    for (i=0;i<n;i++)
        if (a[i])
            m++;
    while (m) {
        if (!cnt[m+1]) {
            poz[m]=solj;
            cnt[m--]=t[solj];
            k=q[soli][solj];
            sol-=t[solj];
            soli-=1<<solj;
            soll=solj;solj=k;
        }
        else {
            poz[m]=solj;
            cnt[m]=t[solj]-com[poz[m]][poz[m+1]];
            m--;
            k=q[soli][solj];
            soli-=1<<solj;
            soll=solj;solj=k;
            sol-=cnt[m+1];
        }
    }
    for (i=1;cnt[i];i++)
        strncpy(af+strlen(af),s[poz[i]]+1,cnt[i]);
    printf("%s",af);
    return 0;
}
