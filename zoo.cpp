#include <fstream>
#include <algorithm>
#define nmax 16100
using namespace std;
ifstream f("zoo.in");
ofstream g("zoo.out");
int a[nmax],b[nmax],p[nmax],q[nmax];
int n,m,a1,b1,a2,b2;
int x[nmax],y[nmax];


int bs(int w,int r[],int t[])
{
    int sol,bit=1<<20;
    for (;bit;bit=bit>>1)
        if (sol+bit<=n&&w<=r[sol+bit])
            sol+=bit;
    return t[sol];
}
int bslow(int w,int r[],int t[])
{


}
int main()
{
    int i,j;
    f>>n;
    //citire
    for (i=1;i<=n;i++) {
        f>>x[i]>>y[i];
        a[i]=x[i];
        b[i]=y[i];
    }
    //sortare
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    a[0]=b[0]=-1<<31;
    for (i=1;i<=n;i++) {
        if (a[i]!=a[i-1])

            p[i]=p[i-1]+1;
        else
            p[i]=p[i-1];

        if (b[i]!=b[i-1])

            q[i]=q[i-1]+1;
        else
            q[i]=q[i-1];
    }
    //normalizare
    for (i=1;i<=n;i++) {
        x[i]=bs(x[i],a,p);
        y[i]=bs(y[i],b,q);
    }
    //creeare arbore de intervale


    //raspundere la query in timp logaritmic
    f>>m;
    for (i=1;i<=m;i++) {
        f>>a1>>b1>>a2>>b2;
        a1=bslow(a1,a,p);
        b1=bslow()

    }



    return 0;
}
