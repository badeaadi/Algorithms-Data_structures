#include <cstdio>
#include <fstream>
#include <cstring>
#include <vector>
#define maxim 1005
#define u 73
#define mod1 1000007
#define mod2 1000023
using namespace std;
ifstream f("tastatura.in");
ofstream g("tastatura.out");
char s[maxim],t[55];
int d[maxim],v[maxim];
int n,x,h1[maxim],h2[maxim],ha1,ha2;
int p1,p2,r;
vector <int> q[maxim];


void solvedynamic()
{
    int i,j;
    f.getline(t,55);
    r=strlen(t);

    if (r>x) return;

    for (i=0;i<r;i++) {
            ha1=(ha1*u+t[i]-'0')%mod1;
            ha2=(ha2*u+t[i]-'0')%mod2;
    }

    for (i=1;i<=r;i++) {
            h1[i]=(h1[i-1]*u+v[i])%mod1;
            h2[i]=(h2[i-1]*u+v[i])%mod2;
    }
    p1=1;p2=1;
    for (i=1;i<=r;i++) {
            p1=(p1*u)%mod1;
            p2=(p2*u)%mod2;
    }

    for (i=r+1;i<=x;i++){
            h1[i]=(h1[i-1]*u+v[i]-p1*v[i-r])%mod1;
            while (h1[i]<0) h1[i]+=mod1;

            h2[i]=(h2[i-1]*u+v[i]-p2*v[i-r])%mod2;
            while (h2[i]<0) h2[i]+=mod2;
    }
    for (i=r;i<=x;i++)
        if (h1[i]==ha1&&h2[i]==ha2)
            q[i].push_back(i-r);


    ha1=0;ha2=0;
}

int main()
{
    int i;
    f.getline(s,maxim);
    x=strlen(s);
    for (i=1;i<=x;i++) v[i]=s[i-1]-'0';
    f>>n;f.get();

    for (i=1;i<=x;i++)
            d[i]=i;
    for (i=1;i<=n;i++)
            solvedynamic();
    for (i=1;i<=x;i++)
            for (vector <int> ::iterator it=q[i].begin();it!=q[i].end();it++)
                        d[i]=min(d[i],d[*it]+1);

    g<<d[x];
    return 0;
}
