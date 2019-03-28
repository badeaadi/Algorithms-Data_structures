#include <fstream>
#include <cstring>
#define nmax 1000005
#define mod1 100023
#define mod2 100007
using namespace std;
ifstream f("superstring.in");
ofstream g("superstring.out");
int n,m,p1,q1;
int p[nmax],q[nmax];
char a[nmax],b[nmax];


int build(char *x,char *y)
{
    int i,j,sol=1<<20;
    n=strlen(x);m=strlen(y);
    p[n-1]=q[n-1]=1;

    for (i=n-2;i>=0;i--) {
        p[i]=(p[i+1]*10)%mod1;
        q[i]=(q[i+1]*10)%mod2;
    }
    p[n]=q[n]=0;

    for (i=n-1;i>=0;i--) {
        p[i]=(p[i]*(x[i]-'a'+1)+p[i+1])%mod1;
        q[i]=(q[i]*(x[i]-'a'+1)+q[i+1])%mod2;
    }
    p1=0;q1=0;
    for (i=0;i<n&&i<m;i++) {
        p1=(p1*10+y[i]-'a'+1)%mod1;
        q1=(q1*10+y[i]-'a'+1)%mod2;
        if (p1==p[n-i-1]&&q1==q[n-i-1])
            sol=min(sol,n+m-(i+1));
    }
    return sol;
}

void solvetest()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    f.getline(a,nmax);
    f.getline(b,nmax);
    g<<min(build(a,b),build(b,a))<<'\n';
}

int main()
{
    int t;
    f>>t;f.get();
    for (;t;t--)
        solvetest();

    return 0;
}
