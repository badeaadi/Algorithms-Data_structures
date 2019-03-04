//Problema AI , Clasa a X-a
//Solutie Badea Adrian , memroie folosita 16MB,
//Prima cerinta O(n^2) Programare dinamica
//A doua cerinta O(n^2+lee)
//Expected Score 100/100
#include <fstream>
#include <cstdio>
#define nmax 1005
using namespace std;
ifstream f("ai.in");
ofstream g("ai.out");
const int dl[]={1,-1,0,0};
const int dc[]={0,0,1,-1};

short cx[nmax*nmax*2],cy[nmax*nmax*2];//8MB
short t[nmax][nmax];//2MB
int n,k,v[nmax][nmax],x,y; //4MB
int xt,yt,xs1,ys1,xs2,ys2,xr1,yr1,xr2,yr2;
short q[nmax][nmax];//2MB
int l1[nmax],c1[nmax],nr1;
int l2[nmax],c2[nmax],nr2;
int s1r1,s2r1,s1r2,s2r2;


void solvea()
{
    int i,j,sol=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (t[i][j]==-1) {
                q[i][j]=q[i][j-1]+1;
                sol=max(sol,int(q[i][j]));
            }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            q[i][j]=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (t[i][j]==-1) {
                q[i][j]=q[i-1][j]+1;
                sol=max(sol,int(q[i][j]));
            }
    g<<sol<<'\n';

}

void lee(int x,int y)
{
    int i,j,p=0,u=1,l,c;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (t[i][j]!=-1)
                v[i][j]=1<<30;
    cx[++p]=x;cy[p]=y;
    v[x][y]=0;
    for (;p<=u;p++) {
        l=cx[p];
        c=cy[p];
        for (i=0;i<=3;i++)
            if (v[l][c]+1<v[l+dl[i]][c+dc[i]]) {
                v[l+dl[i]][c+dc[i]]=v[l][c]+1;
                u++;
                cx[u]=l+dl[i];
                cy[u]=c+dc[i];
            }
    }
}
int determinant(int x2,int y2,int x3,int y3,int x4,int y4)
{
    if (x2>=x4&&y2>=y4) {
        swap(x2,x4);
        swap(y2,y4);
    }

    if (!(x3>=x2&&x3<=x4))
        return -1;
    if (!(y3>=y2&&y3<=y4))
        return -1;
    return x2 * y3 + x3 * y4 + x4 * y2 - y3* x4 - y4 * x2 - y2 * x3;

}

int main()
{
    int i,j;
    f>>n;
    f>>xt>>yt>>xs1>>ys1>>xs2>>ys2>>xr1>>yr1>>xr2>>yr2;
    t[xt][yt]=-1;
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x>>y;
        t[x][y]=-1;
    }
    solvea();
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (t[i][j]!=-1) {
            if (determinant(xs1,ys1,i,j,xt,yt)==0) {
                ++nr1;
                l1[nr1]=i;c1[nr1]=j;

            }
            if (determinant(xs2,ys2,i,j,xt,yt)==0) {
                ++nr2;
                l2[nr2]=i;c2[nr2]=j;
            }
        }
    l1[++nr1]=xs1;c1[nr1]=ys1;
    l2[++nr2]=xs2;c2[nr2]=ys2;

    lee(xr1,yr1);
    s1r1=1<<30;s1r2=1<<30;
    s2r1=1<<30;s2r2=1<<30;
    for (i=1;i<=nr1;i++)
        s1r1=min(s1r1,v[l1[i]][c1[i]]);
    for (i=1;i<=nr2;i++)
        s2r1=min(s2r1,v[l2[i]][c2[i]]);
    lee(xr2,yr2);
    for (i=1;i<=nr1;i++)
        s1r2=min(s1r2,v[l1[i]][c1[i]]);
    for (i=1;i<=nr2;i++)
        s2r2=min(s2r2,v[l2[i]][c2[i]]);
    g<<min(max(s1r1,s2r2),max(s1r2,s2r1));
    return 0;
}
