#include <fstream>
#include <algorithm>
using namespace std;

FILE *f=fopen("tg.in","r");
FILE *g=fopen("tg.out","w");


int n;
bool ok[4000010];
long long sol;

int main()
{int i,j;
fscanf(f,"%d",&n);

for (i = 1; i <= n; ++i)
        if (!ok[i])

            for (int j = 1; i * j * j <= n; ++j)
                    {sol += j - 1;
                     ok[i * j * j] = true;
                     }
fprintf(g,"%d\n",sol);
return 0;
}
