#include <fstream>
#include <algorithm>
#define nmax 2000005
using namespace std;
ifstream f("toys.in");
ofstream g("toys.out");
long long sol;
int n,l,m,s,x,y,z,v;;
int d[nmax];
char t[nmax];


int main()
{
    int i,r;
    f>>n>>l>>m;
    f>>s>>x>>y>>z>>v;
    d[1]=s;t[1]=1;
    for (i=2;i<=n+1;++i) {
        d[i]=(1LL*x*d[i-1]+1LL*y*(i-1))%(l-1)+1;
        t[i]=(1LL*z*d[i-1]+1LL*v*(i-1))%2;
        if (t[i-1]==0)
            d[i-1]=2*l-d[i-1];
        else
            d[i-1]=2*l+d[i-1];
    }
    r=m/n;
    if (m%n==0) {
        sol+=1LL*(r-1)*1LL*2*l;
        m=n;
    }
    else {
        sol+=1LL*r* 2*l;
        m%=n;
    }
    nth_element(d+1,d+m,d+n+1);
    sol+=1LL*d[m];
    g<<sol;


    return 0;
}
