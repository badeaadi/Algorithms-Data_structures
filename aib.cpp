#include <cstdio>
#include <fstream>
#define ub(x) (x&(-x))
using namespace std;
ifstream f("aib.in");
ofstream g("aib.out");
int n,m;
int aib[100001];
short v[100001];


void add(int a,int val)
{
    int i;
    for (i=a;i<=n;i+=ub(i))
        aib[i]+=val;
}
int sum(int a)
{
    int i,s=0;
    for (i=a;i>=1;i-=ub(i))
        s+=aib[i];
    return s;
}


int main()
{
    int a,b,i,j,k,st,dr,mijl,s;
    f>>n>>m;
    for (i=1;i<=n;i++) {
        f>>v[i];
        add(i,v[i]);
    }
    for (;m;m--) {
        f>>k;
        if (k==0) {
            f>>a>>b;
            add(a,b);
        }
        if (k==1) {
            f>>a>>b;
            g<<sum(b)-sum(a-1)<<'\n';
        }
        if (k==2) {
            f>>a;
            st=1;dr=n;
            while (st<=dr) {
                mijl=(st+dr)>>1;
                s=sum(mijl);
                if (s==a) {
                    g<<mijl<<'\n';
                    break;
                }
                else
                    if (s<a)
                        st=mijl+1;
                    else
                        dr=mijl-1;
            }
            if (s!=a)
                g<<-1<<'\n';
        }
    }
    return 0;
}
