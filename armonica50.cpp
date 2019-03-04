#include <fstream>
#define nmax 30000
using namespace std;
ifstream f("armonica.in");
ofstream g("armonica.out");
long long c,x[nmax],y[nmax];
int a,b,sol;

int main()
{
    f>>b;
    for (a=b/2+1;a<=b;a++)
        if ((1LL*a*b)%(2*a-b)) {
            sol++;
            x[sol]=a;
            y[sol]=(1LL*a*b)%(2*a-b);
        }
    g<<2*sol+1<<'\n';
    for (int i=1;i<=sol;i++) {
        g<<x[i]<<' '<<y[i]<<'\n';
        g<<y[i]<<' '<<x[i]<<'\n';
    }
    return 0;
}
