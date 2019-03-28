#include <fstream>
#define eps 0.00001
using namespace std;
ifstream f("tictac.in");
ofstream g("tictac.out");
long double x,y,z;
int n;


int main()
{
    int i,j;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>x>>y;
        while (x>=30)
            x-=30;
        z=x-y/12;
        if (z>=-eps&&z<=eps)
            g<<'1'<<'\n';
        else
            g<<'0'<<'\n';
    }

    return 0;
}
