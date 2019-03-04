#include <fstream>
#include <algorithm>
#define nmax 10005
#define infd 1000000.0
using namespace std;
ifstream f("babacu.in");
ofstream g("babacu.out");
struct punctdual{double a;double b;int n;};
punctdual v[nmax],s[nmax];
int n,k,sol;

double det(const punctdual &x,const punctdual &y,const punctdual &z)
{
    return (y.a-x.a)*(z.b-x.b)-(z.a-x.a)*(y.b-x.b);
}
bool sortcomp(const punctdual &x,const punctdual &y)
{
    return det(v[1],x,y)>0;
}

int main()
{
    int i,j,p,q,t;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>p>>q>>t;
        v[i].a=1.0*p/t;
        v[i].b=1.0*q/t;
        v[i].n=i;
    }
    n++;v[n].a=1.0/infd;v[n].b=0;v[n].n=n;
    n++;v[n].a=-1.0/infd;v[n].b=0;v[n].n=n;
    n++;v[n].a=0;v[n].b=1.0/infd;v[n].n=n;
    n++;v[n].a=0;v[n].b=-1.0/infd;v[n].n=n;

    for (i=1,j=2;j<=n;j++)
        if (v[j].b<v[i].b||(v[j].b==v[i].b&&v[j].a<v[i].a))
            i=j;
    swap(v[1],v[i]);
    sort(v+2,v+n+1,sortcomp);
    s[++k]=v[1];
    s[++k]=v[2];
    for (i=3;i<=n;i++) {
        while (k>=2&&det(s[k-1],s[k],v[i])<=0)
            k--;
        s[++k]=v[i];
    }
    sol=k;
    for (i=1;i<=k;i++)
        if (s[i].n>=n-3)
            sol--;
    g<<sol<<'\n';


    return 0;
}
