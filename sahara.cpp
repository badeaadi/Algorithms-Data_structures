#include <fstream>
#define nmax 1005
using namespace std;
ifstream f("sahara.in");
ofstream g("sahara.out");

int v[nmax][nmax],a[nmax][nmax];
short b[nmax][nmax];
short l[nmax*nmax],c[nmax*nmax];

int maximtot,p1,l1,c1;
int n,m,p,q,cnt,nrtot;
int x1,y1,x2,y2;

const int dl[4]={1,-1,0,0};
const int dc[4]={0,0,1,-1};


int main()
{
    int i,j,t;
    f>>n>>m>>p;
    f>>q;
    for (i=1;i<=q;i++) {
        f>>x1>>y1>>x2>>y2>>t;
        v[x1][y1]+=t;
        v[x2+1][y1]-=t;
        v[x1][y2+1]-=t;
        v[x2+1][y2+1]+=t;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            a[i][j]=v[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];

    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (b[i][j]==0&&a[i][j]>p) {
                l[1]=i;
                c[1]=j;
                b[i][j]=1;
                for (p1=1,nrtot=1;p1<=nrtot;p1++)
                    for (t=0;t<4;t++) {
                        l1=l[p1]+dl[t];
                        c1=c[p1]+dc[t];
                        if (l1>=1&&l1<=n&&c1>=1&&c1<=m&&b[l1][c1]==0&&a[l1][c1]>=p) {
                            b[l1][c1]=1;
                            nrtot++;
                            l[nrtot]=l1;
                            c[nrtot]=c1;
                        }
                    }
                if (nrtot>maximtot)
                    maximtot=nrtot;
            }
    g<<maximtot<<'\n';

    return 0;
    }
