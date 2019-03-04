#include <fstream>
#define nmax 260
using namespace std;
ifstream f("rf.in");
ofstream g("rf.out");
int n,v[nmax][nmax],a[nmax][nmax];



void writematrix(int m[][nmax])
{
    int i,j;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            g<<m[i][j]<<' ';
        g<<'\n';
    }

}

int main()
{
    int i,j,k;
    f>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            f>>v[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (i!=j)
                a[i][j]=1;

    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++) if (i!=k)
            for (j=1;j<=n;j++) if (j!=i&&j!=k)

                    if (v[i][k]+v[k][j]<v[i][j]||(v[i][k]+v[k][j]==v[i][j]&&a[i][k]+a[k][j]>a[i][j])) {

                        v[i][j]=v[i][k]+v[k][j];
                        a[i][j]=a[i][k]+a[k][j];
                    }
    writematrix(v);
    writematrix(a);

    return 0;
}
