#include <fstream>
#define ub(i) i&(-i)
#define nmax 30010
using namespace std;
ifstream f("schi.in");
ofstream g("schi.out");
int v[nmax],aib[nmax];
int n,sol[nmax];


int aibsum(int poz)
{
    int sum=0;
    for (;poz>=1;poz-=ub(poz))
        sum+=aib[poz];
    return sum;
}
void aibadd(int poz,int val)
{
    for (;poz<=n;poz+=ub(poz))
        aib[poz]+=val;
}

int main()
{
    int i,j,x,p,q;
    f>>n;
    for (i=1;i<=n;i++)
        f>>v[i];
    for (i=1;i<=n;i++)
        aibadd(i,1);
    for (i=n;i>=1;i--) {
        p=0;v[i]--;
        for (q=1<<14;q;q>>=1)
            if (p+q<=n&&aibsum(p+q)<=v[i])
                p+=q;
        p++;
        sol[p]=i;
        aibadd(p,-1);
    }
    for (i=1;i<=n;i++)
        g<<sol[i]<<'\n';
    return 0;
}
