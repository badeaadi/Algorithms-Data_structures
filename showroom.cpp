#include <bits/stdc++.h>
#define nmax 505
#define dmax 105
#define mod 9001
using namespace std;
ifstream f("showroom.in");

int n,m,a,r,k,nrm,tot[nmax],soltip;
char s[nmax*dmax];
struct model{char s[25];int t;} v[nmax*dmax];
int t[nmax],sol,o[nmax];

bool compmodels(const model &a,const model &b)
{
    int an=strlen(a.s);
    int bn=strlen(b.s);
    if (an!=bn)
        return an<bn;
    int i=0;
    while (a.s[i]&&a.s[i]==b.s[i])
        i++;
    return a.s[i]<b.s[i];
}
int tata(int x)
{
    int y=x,z;
    while (t[x]>0)
        x=t[x];
    while (t[y]>0) {
        z=t[y];
        t[y]=x;
        y=z;
    }
    return x;
}
void tieup(int x,int y)
{
    if (x==y)
        return;
    if (x>y)
        swap(x,y);

    t[x]+=t[y];
    t[y]=x;
}

void euclid(int a,int b,int &x,int &y)
{
    if (b==0) {
        x=1;
        y=0;
        return;
    }
    int x0=0,y0=0;
    euclid(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
}
int im(int n)
{
    int x=0,y=0;
    euclid(n,mod,x,y);
    return x;
}
int comb(int n,int k)
{
    if (n<k)
        return 0;

    int sol=1,a;
    int i;
    for (i=n-k+1;i<=n;i++)
        sol=(1LL*sol*i)%mod;
    for (a=1,i=1;i<=k;i++)
        a=(1LL*a*i)%mod;
    sol=(1LL*sol*im(a))%mod;
    sol>=0?:sol+=mod;

    return sol;
}
int solvecomb(int n,int k)
{
    long long prod=1;
    while (n) {
        prod=1LL* prod * comb(n%mod,k%mod) %mod;
        n/=mod;
        k/=mod;
    }
    return prod;
}

int main()
{
    int i,j,u;
    f>>n>>a>>r>>k;f.get();
    for (u=1;u<=n;u++) {
        f.getline(s,50000);
        m=strlen(s);
        i=0;t[u]=-1;
        while (s[i]==' ')
            i++;
        for (j=i;j<=m;j++)
            if (s[j]==' '||s[j]==0) {
                strncpy(v[++nrm].s,s+i,j-i);
                v[nrm].t=u;

                i=j+1;
                while (s[i]==' ')
                    i++,j++;
            }
    }
    sort(v+1,v+nrm+1,compmodels);
    tot[v[1].t]++;
    for (i=2;i<=nrm;i++)
        if (strcmp(v[i].s,v[i-1].s)==0)
            tieup(tata(v[i-1].t),tata(v[i].t));

    for (i=1;i<=n;i++)
        if (t[i]<0) {
            sol++;
        }
    ofstream g("showroom.out");
    g<<sol<<'\n';
    j=0;
    for (i=1;i<=nrm;i++)
        if (strcmp(v[i].s,v[i-1].s))
            o[tata(v[i].t)]++;

    soltip=1;
    for (i=1;i<=n;i++)
        if (t[i]<0) {
            if (a<=o[i])
                soltip=(1LL*soltip*solvecomb(o[i],a))%mod;
            a+=r;
            a%=k;
        }
    g<<soltip<<'\n';
    return 0;
}
