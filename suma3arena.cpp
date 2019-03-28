#include <fstream>
#define nmax 10
using namespace std;
ifstream f("suma3.in");
ofstream g("suma3.out");

const int dl[]={0,0,1,-1,1,1,-1,-1};
const int dc[]={1,-1,0,0,1,-1,1,-1};
int minim=1<<30,n,k;
int val[nmax*nmax];//valorile nodurilor
int a[nmax*nmax][nmax],p[nmax*nmax]; //lista de adiacenta
int v[nmax*nmax],uz[nmax*nmax],m;

inline int num(int l, int c)
{
    return l*(m)+c;
}

void bkt(int nr,int x)
{
    int i,r,y;
    if (x>minim)
        return;
    if (nr<=k) {
        r=v[nr-1];
        for (i=1;i<=p[r];i++) {
            y=a[r][i];
            if (uz[y]==0) {
                uz[y]=1;
                v[nr]=y;
                bkt(nr+1,x+nr*val[y]);
                v[nr]=0;
                uz[y]=0;
            }
        }
    }
    else
        minim=min(minim,x);

}

int main()
{
    int i,j,t,nr;
    f>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            f>>a[i][j];
            val[num(i,j)]=a[i][j];
            if (a[i][j])
                ++k;
        }

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)  {
            nr=num(i,j);
            for (t=0;t<8;t++)
                if (a[i+dl[t]][j+dc[t]])
                    a[nr][++p[nr]]=num(i+dl[t],j+dc[t]);
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i][j]) {
                v[1]=num(i,j);
                uz[num(i,j)]=1;
                bkt(2,a[i][j]);
                uz[num(i,j)]=0;
                v[1]=0;
            }
    g<<minim;
    return 0;
}
