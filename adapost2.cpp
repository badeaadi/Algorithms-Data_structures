#include <cstdio>
#include <fstream>
#include <iomanip>
#include <cmath>
#define nmax 50005
using namespace std;
ifstream f("adapost2.in");
ofstream g("adapost2.out");
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
double x[nmax],y[nmax];
double sx,sy,a,b;
int n;

double solvy(const double &a,const double &b)
{
    double sol=0;
    for (int i=1;i<=n;i++)
        sol+=sqrt((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i]));
    return sol;
}
int main()
{
    int i,ok;
    f>>n;
    for (i=1;i<=n;i++)
        f>>x[i]>>y[i];
    double sol=solvy(sx,sy);
    for (double d=500;d>=0.001;d/=2.0) {
        ok=0;
        for (i=0;i<4;i++) {
            a=sx+1.0*dx[i]*d;
            b=sy+1.0*dy[i]*d;
            if (solvy(a,b)<sol) {
                sx=a;
                sy=b;
                sol=solvy(sx,sy);
                ok=1;
            }
        }
        if (ok)
            d*=2;
    }
    g<<setprecision(7)<<fixed<<sx<<' '<<sy;
    return 0;
}


