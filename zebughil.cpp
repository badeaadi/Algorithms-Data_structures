#include <fstream>
#include <algorithm>
#define nmax 18
using namespace std;
ifstream f("zebughil.in");
ofstream g("zebughil.out");
int n,cam,v[nmax],a[nmax],sol;


void generare(int num,int numgr)
{
    if (numgr>=sol)
            return;
    if (num<=n) {

        int i;
        for (i=numgr;i>=1;i--)
            if (a[i]+v[num]<=cam) {
                a[i]+=v[num];
                generare(num+1,numgr);
                a[i]-=v[num];
            }
        a[numgr+1]=v[num];
        generare(num+1,numgr+1);
    }
    else
        sol=min(sol,numgr);
}
void solveone()
{
    int i,j;
    f>>n>>cam;
    for (i=1;i<=n;i++)
        f>>v[i];
    sort(v+1,v+n+1);
    sol=1<<30;
    generare(1,0);
    g<<sol<<'\n';
}
int main()
{
    int t;
    for (t=1;t<=3;t++)
        solveone();

    return 0;
}
