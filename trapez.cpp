#include <fstream>
#include <algorithm>
#include <cmath>
#define eps 0.000001
#define nmax 1010
using namespace std;
ifstream f("trapez.in");
ofstream g("trapez.out");
long long sol;
int n,m1,m2;
int x[nmax],y[nmax];
struct elem {int p;int q;};
elem v1[nmax*nmax/2],v2[nmax*nmax/2];


int cmmdc(int a,int b)
{
    if (b==0) return a;
    return cmmdc(b,a%b);
}
int modul(int x)
{
    if (x<0) return -x;
    return x;
}
bool comp(const elem &a , const elem &b)
{
    if (a.q==0) return true;
    if (b.q==0) return false;
    double r1=double(a.p)/double(a.q);
    double r2=double(b.p)/double(b.q);
    if (abs(r1-r2)<eps) return false;
    return r1<r2;

}
bool egal(const elem &a,const elem &b)
{
    if (a.p==b.p&&a.q==b.q)
        return true;
    return false;
}

void add(int p1,int q1)
{
    int d=modul(cmmdc(p1,q1));
    p1/=d;
    q1/=d;


    if (p1*q1>=0) {
        m1++;
        v1[m1].p=modul(p1);
        v1[m1].q=modul(q1);
    }
    else {
        m2++;
        v2[m2].p=modul(p1);
        v2[m2].q=modul(q1);
    }


}
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>x[i]>>y[i];
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
                add((y[j]-y[i]),(x[j]-x[i]));

    sort(v1+1,v1+m1+1,comp);
    i=1;
    while (i<=m1) {
        j=i+1;
        while (j<=m1&&egal(v1[j],v1[j-1])==true)
            j++;
        sol+=1LL*(j-i)*(j-i-1)/2;
        i=j;
    }

    sort(v2+1,v2+m2+1,comp);

    i=1;
    while (i<=m2) {
        j=i+1;
        while (j<=m2&&egal(v2[j],v2[j-1])==true)
            j++;
        sol+=1LL*(j-i)*(j-i-1);
        i=j;
    }

    g<<sol<<'\n';

    return 0;
}
