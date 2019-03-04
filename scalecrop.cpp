#include <fstream>
#include <iomanip>
using namespace std;
int a,b,x,y;
long double r,k,p;

ifstream f("scalecrop.in");
ofstream g("scalecrop.out");


int main()
{
    f>>a>>b>>x>>y;
    r=max(1.0*a/x,1.0*b/y);;

    k=x*r;
    p=y*r;

    g<<setprecision(4)<<fixed<<k<<' '<<p<<'\n';
    return 0;
}
