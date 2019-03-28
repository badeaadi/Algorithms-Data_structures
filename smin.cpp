#include <fstream>
#include <cmath>
#include <iomanip>
#define nmax 18
using namespace std;
ifstream f("smin.in");
ofstream g("smin.out");
int n,x[nmax],y[nmax];
int v[1<<nmax];
int p[nmax][nmax][nmax];

int arie(int a1,int b1,int a2,int b2,int a3,int b3)
{
    return abs(a1*b2+a2*b3+a3*b1-b2*a3-b3*a1-b1*a2);
}

int main()
{
    int i,ifn,a,b,c;
    f>>n;
    for (i=0;i<n;i++)
        f>>x[i]>>y[i];
    for (a=0;a<n;a++)
        for (b=a+1;b<n;b++)
            for (c=b+1;c<n;c++)
                p[a][b][c]=arie(x[a],y[a],x[b],y[b],x[c],y[c]);

    for (i=1;i<=(1<<n);i++)
        v[i]=1<<30;

    for (i=0;i<(1<<n);i++) {
        if (v[i]!=(1<<30)&&v[i]<v[1<<n])

            for (a=0;a<n;a++)
                for (b=a+1;b<n;b++)
                    for (c=b+1;c<n;c++) {

                        ifn=i;
                        ifn|=1<<a;
                        ifn|=1<<b;
                        ifn|=1<<c;

                        if (v[i]>v[ifn]||i==ifn)
                            continue;

                        v[ifn]=min(v[ifn],v[i]+p[a][b][c]);
                    }
    }
    double sol=v[(1<<n)-1]/2.0;
    g<<setprecision(6)<<fixed<<sol<<'\n';

    return 0;
}
