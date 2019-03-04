#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define nmax 25
#define inf 1000000000
#define eps 0.001
using namespace std;
ifstream f("arie.in");
ofstream g("arie.out");
struct punct{int x;int y;} a[nmax],b[nmax];
struct punctdouble{double x;double y;} v[nmax*nmax],s[nmax*nmax],l,o;
int n,m,k,p;


void ecuatiadreptei(punct x,punct y,double &a,double &b,double &c)
{
    a=y.y-x.y;
    b=-(y.x-x.x);
    c=-a*x.x-b*x.y;
}
punctdouble intersect(punct x,punct y,punct z,punct t)
{
    double a1,b1,c1,a2,b2,c2;
    ecuatiadreptei(x,y,a1,b1,c1);
    ecuatiadreptei(z,t,a2,b2,c2);
    double p=0;
    if (a1&&a2)
        p=1.0*a2/a1;
    if (b1&&b2)
        p=1.0*b2/b1;
    if (p==0) {
        if (a1)
            l.x=-c1/a1;
        else
            l.x=-c2/a2;

        if (b1)
            l.y=-c1/b1;
        else
            l.y=-c2/b2;

        return l;
    }
    a1*=p;b1*=p;c1*=p;
    a2-=a1;b2-=b1;c2-=c1;
    if (abs(b2)<=eps&&abs(a2)<=eps) {
        l.x=inf;
        l.y=inf;
        return l;
    }
    if (abs(b2)<=eps) {
        l.x=-c2/a2;
        l.y=(-c1-l.x*a1)/b1;
    }
    else {
        l.y=-c2/b2;
        l.x=(-c1-l.y*b1)/a1;
    }
    return l;
}

double determinant(punctdouble a,punctdouble b,punctdouble c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double determinant2(punctdouble a,punct b,punct c)
{
    double p=(1.0*b.x-1.0*a.x)*(1.0*c.y-1.0*a.y);
    double q=-1.0*(1.0*c.x-1.0*a.x)*(1.0*b.y-1.0*a.y);
    return p+q;
}
int sortcomp(punctdouble a,punctdouble b)
{
    return determinant(s[1],a,b)>0;
}
int inside(punct a[],int n,punctdouble k)
{
    int i,e,r;
    double p,q;
    for (i=1;i<=n;i++) {
        if (abs(determinant2(k,a[i],a[i+1]))<=eps) {
            e=min(a[i].x,a[i+1].x);
            r=max(a[i].x,a[i+1].x);
            if (k.x<e||k.x>r)
                return 0;

            e=min(a[i].y,a[i+1].y);
            r=max(a[i].y,a[i+1].y);
            if (k.y<e||k.y>r)
                return 0;
            return 1;
        }
    }
    for (i=2;i<=n;i++) {
        p=determinant2(k,a[i-1],a[i]);
        q=determinant2(k,a[i],a[i+1]);
        if (p*q<0)
            return 0;
    }
    return 1;
}
int insidepolygon(punctdouble k)
{
    if (inside(a,n,k)&&inside(b,m,k))
        return 1;
    return 0;
}
int notalready(punctdouble k)
{
    int i;
    for (i=1;i<=p;i++)
        if (abs(s[i].x-k.x)<=eps&&abs(s[i].y-k.y)<=eps)
            return 0;
    return 1;
}
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>a[i].x>>a[i].y;
        k++;
        v[k].x=a[i].x;
        v[k].y=a[i].y;
    }
    a[n+1]=a[1];
    f>>m;
    for (i=1;i<=m;i++) {
        f>>b[i].x>>b[i].y;
        k++;
        v[k].x=b[i].x;
        v[k].y=b[i].y;
    }
    b[m+1]=b[1];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            l=intersect(a[i],a[i+1],b[j],b[j+1]);
            if (!(abs(l.x-inf)<=eps))
                v[++k]=l;
        }
    for (i=1;i<=k;i++) {
        if ((v[i].x+972)<=eps) {
            i++;
            i--;
        }
        if ((insidepolygon(v[i])))
            if (notalready(v[i]))
                s[++p]=v[i];
    }
    sort(s+2,s+p+1,sortcomp);

    /*
    for (i=1;i<=p;i++)
        g<<setprecision(2)<<fixed<<s[i].x<<' '<<s[i].y<<'\n';
    */

    s[p+1]=s[1];
    double q=0;
    for (i=1;i<=p;i++)
        q+=determinant(o,s[i],s[i+1]);
    q=abs(q);
    q/=2;
    g<<setprecision(3)<<fixed<<q<<'\n';
    return 0;
}
