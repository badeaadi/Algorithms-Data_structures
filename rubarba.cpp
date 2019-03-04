#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define nmax 100005
using namespace std;
ifstream f("rubarba.in");
ofstream g("rubarba.out");
int n,k;
double sol=1<<30;
struct point{int x;int y;} p[nmax],s[nmax];

struct pointdouble{double x;double y;};

int determinant(const point &a,const point &b,const point &c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int sortcomp(const point &a,const point &b)
{
    return determinant(a,b,p[1])<0;
}
double distanta(const point &a,const point &b)
{
    return sqrt(double((1ll*a.x-b.x)*(a.x-b.x)+(1ll*a.y-b.y)*(a.y-b.y)));
}

double distantadouble(const pointdouble &a,const pointdouble &b)
{
    return sqrt(((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
void solve(point a,point b)
{
    if (!(a.x<=b.x))
        swap(a,b);
    pointdouble p,l,c,aux;
    l.x=a.x;l.y=a.y;
    c.x=b.x;c.y=b.y;
    double m,a1,b1,c1,a2,b2,c2,dist=0;

    a2=(b.y-a.y);
    b2=-(b.x-a.x);
    c2=-a.x*(b.y-a.y)+a.y*(b.x-a.x);

    for (int i=1;i<=k;i++)
        if ((s[i].x!=a.x||s[i].y!=a.y)&&(s[i].x!=b.x||s[i].y!=b.y)) {
            if (b.x==a.x) {
                p.x=a.x;
                p.y=s[i].y;
            }else
            if (b.y==a.y) {
                p.x=s[i].x;
                p.y=a.y;
            }else {
                m=1.0*(b.y-a.y)/(b.x-a.x);
                m=(-1)/m;

                a1=m;
                b1=-1;
                c1=-m*s[i].x+s[i].y;

                p.x=c2*b1-c1*b2;
                p.x/=a1*b2-a2*b1;

                p.y=-c1-a1*p.x;
                p.y/=b1;
            }
            aux.x=s[i].x;
            aux.y=s[i].y;
            dist=max(dist,distantadouble(aux,p));
            if (p.x>c.x)
                c=p;
            if (p.x<l.x)
                l=p;
        }
    sol=min(sol,dist*distantadouble(l,c));
}
int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
        f>>p[i].x>>p[i].y;
    j=1;
    for (i=2;i<=n;i++)
        if (p[i].y<p[j].y||(p[i].y==p[j].y&&p[i].x<p[j].x))
            j=i;
    swap(p[1],p[j]);
    sort(p+2,p+1+n,sortcomp);
    s[++k]=p[1];
    s[++k]=p[2];
    for (i=3;i<=n;i++) {
        while (k>=2&&determinant(s[k],s[k-1],p[i])<0)
            k--;
        s[++k]=p[i];
    }
    s[k+1]=p[1];
    for (i=1;i<=k;i++)
        solve(s[i],s[i+1]);
    g<<setprecision(2)<<fixed<<sol<<'\n';

    return 0;
}
