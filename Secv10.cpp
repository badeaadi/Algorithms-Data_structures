#include <fstream>
#include <cstring>
#define nmax 100005
#define k 73
#define mod1 1000007
#define mod2 1000023
using namespace std;
ifstream f("secv10.in");
ofstream g("secv10.out");
int sst[nmax],sdr[nmax];
int n,nst,ndr,m1[nmax],m2[nmax];
int a1,a2,b1,b2;
char s[nmax],st[nmax],dr[nmax];
long long sol;

void solve()
{
    int i,j;
    for (i=0;i<nmax;i++) {
        sst[i]=0;sdr[i]=0;
    }
    memset(s,0,sizeof(s));
    memset(st,0,sizeof(st));
    memset(dr,0,sizeof(dr));
    f.getline(s,nmax);n=strlen(s);
    f.getline(st,nmax);nst=strlen(st);
    f.getline(dr,nmax);ndr=strlen(dr);
    a1=0;a2=0;b1=0;b2=0;
    //Pentru stanga
    for (i=0;i<nst;i++) {
        a1=(a1*k+(st[i]-'A'))%mod1;
        a2=(a2*k+(st[i]-'A'))%mod2;


        b1=(b1*k+(s[i]-'A'))%mod1;
        b2=(b2*k+(s[i]-'A'))%mod2;
    }
    if (a1==b1&&a2==b2)
        sst[0]=1;

    for (i=nst;i<=n;i++) {
        b1=(b1*k+(s[i]-'A')-(s[i-nst]-'A')*m1[nst])%mod1;
        b1=(b1+mod1)%mod1;

        b2=(b2*k+(s[i]-'A')-(s[i-nst]-'A')*m2[nst])%mod2;
        b2=(b2+mod2)%mod2;

        if (a1==b1&&a2==b2)
            sst[i-nst+1]=1;
    }
    //Pentru dreapta
    a1=0;a2=0;b1=0;b2=0;
    for (i=0;i<ndr;i++) {
        a1=(a1*k+(dr[i]-'A'))%mod1;
        a2=(a2*k+(dr[i]-'A'))%mod2;


        b1=(b1*k+(s[i]-'A'))%mod1;
        b2=(b2*k+(s[i]-'A'))%mod2;
    }
    if (a1==b1&&a2==b2)
        sdr[ndr-1]=1;

    for (i=ndr;i<=n;i++) {
        b1=(b1*k+(s[i]-'A')-(s[i-ndr]-'A')*m1[ndr])%mod1;
        b1=(b1+mod1)%mod1;

        b2=(b2*k+(s[i]-'A')-(s[i-ndr]-'A')*m2[ndr])%mod2;
        b2=(b2+mod2)%mod2;

        if (a1==b1&&a2==b2)
            sdr[i]=1;
    }
    for (i=n-2;i>=0;i--)
        sdr[i]+=sdr[i+1];
    for (i=0;i<n;i++)
        if (sst[i]==1)
            sol+=1LL*sdr[i];
    g<<sol<<'\n';
    sol=0;
}


int main()
{
    int i,t;
    m1[0]=1;m2[0]=1;
    for (i=1;i<nmax;i++) {
        m1[i]=(m1[i-1]*k)%mod1;
        m2[i]=(m2[i-1]*k)%mod2;
    }
    f>>t;f.get();
    for (;t;t--)
        solve();

    return 0;
}
