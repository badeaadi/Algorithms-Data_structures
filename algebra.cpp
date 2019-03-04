#include <bitset>
#include <fstream>
#include <iomanip>
#define eps 0.0000001
#define nmax 35
using namespace std;
long double v[nmax][nmax];
long double xsol[nmax*nmax],k;
int n,st[nmax],dr[nmax];
int m,sol[nmax*nmax][nmax],nrsol;
bitset <nmax> uz;


int cuplaj(int x)
{
    uz[x]=1;
    int y;
    for (y=1;y<=n;y++) {
        if (v[x][y]<eps)
            continue;
        if (!dr[y]) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    for (y=1;y<=n;y++) {
        if (v[x][y]<eps)
            continue;
        if (uz[dr[y]]&&cuplaj(dr[y])) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    ifstream f("algebra.in");
    ofstream g("algebra.out");
    int i,j;
    bool ok,stop;

    f>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
                f>>v[i][j];
    stop=true;
    while (stop) {
        m++;
        for (i=1;i<=n;i++) {
            st[i]=0;
            dr[i]=0;
        }
        do
        {
            ok=false;
            uz.reset();
            for (i=1;i<=n;i++)
                if (st[i]==0&&cuplaj(i))
                    ok=true;

        } while (ok);
        k=1;
        for (i=1;i<=n;i++)
            if (v[i][st[i]]<k)
                k=v[i][st[i]];
        xsol[m]=k;
        for (i=1;i<=n;i++) {
            sol[m][i]=st[i];
            v[i][st[i]]-=k;
            if (v[i][st[i]]<0)
                v[i][st[i]]=0;
        }
        stop=false;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (v[i][j]>eps)
                    stop=true;
    }
    g<<m<<'\n';
    for (i=1;i<=m;i++) {
        g<<setprecision(12)<<fixed<<xsol[i]<<'\n';
        for (j=1;j<=n;j++)
            g<<sol[i][j]<<' ';
        g<<'\n';
    }

    return 0;
}
