#include <fstream>
#include <algorithm>
#define maxn 4000005
using namespace std;
ifstream f("tg.in");
ofstream g("tg.out");
long long sol;
bool ok[maxn];


int main()
{   int i,j,n;
    f>>n;
    for (i=1;i<=n;++i)
        if (!ok[i])
            for (int j=1;i*j*j<=n;++j)
                    {sol+=j-1;
                     ok[i*j*j] = true;
                     }
    g<<sol;
return 0;
}
