#include <cstdio>
#include <vector>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <fstream>
#include <cstring>
#include <queue>
#define inf 1<<30
#define nmax 810
using namespace std;
struct point{int x;int y;};
point p[nmax];

double r[nmax][nmax];
int z[nmax][nmax],dest;
short c[nmax][nmax],f[nmax][nmax];
int n,st[nmax],dr[nmax],dtot2,tot,sol;

bitset <nmax*2> uz;
vector <int> v[nmax];
queue <int> q;


double dist(const point &a,const point &b)
{
    return sqrt(double(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int cuplaj(int x)
{
    int i,y;
    uz[x]=1;
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (dr[y]==0) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    for (i=0;i<v[x].size();i++) {
        y=v[x][i];
        if (uz[dr[y]]=0&&cuplaj(dr[y])) {
            st[x]=y;
            dr[y]=x;
            return 1;
        }
    }
    return 0;
}
int solvesol(int mid)
{
    int i,ok;
    for (i=1;i<=n;i++)
        st[i]=0,dr[i]=0;
    do
    {
        ok=0;
        uz.reset();
        for (i=1;i<=n;i++)
            if (st[i]==0&&cuplaj(i))
                ok=1;

    }while (ok);
    tot=0;
    for (i=1;i<=n;i++)
        if (st[i]==0)
            return 0;
    return 1;
}
void make_graph(int mid,int l)
{
    int i,j;
    for (i=1;i<=n;i++)
        v[i].clear();
    for (i=1;i<=n;i++)
        for (j=n+1;j<=2*n;j++)
            if (r[i][j]<=mid) {
                v[i].push_back(l==0?j-n:j);
                if (l==1) {
                    v[j].push_back(i);
                    c[i][j]=1;
                    z[i][j]=r[i][j];z[j][i]=-r[i][j];
                }
            }
    if (l==1) {
        for (i=1;i<=n;i++) {
            v[0].push_back(i);
            v[i].push_back(0);
            c[0][i]=1;
        }
        for (i=n+1;i<=2*n;i++) {
            v[i].push_back(dest);
            v[dest].push_back(i);
            c[i][dest]=1;
        }
    }
}
int d[nmax],t[nmax];

int bfs()
{
    int x,y,i;
    for (i=1;i<=dest;i++)
        d[i]=inf;
    uz.reset();
    q.push(0);
    uz[0]=1;
    while (!q.empty()) {
        x=q.front();
        q.pop();
        uz[x]=0;
        for (i=0;i<v[x].size();i++) {
            y=v[x][i];
            if (f[x][y]<c[x][y]&&d[y]>d[x]+z[x][y]) {
                d[y]=d[x]+z[x][y];
                t[y]=x;
                if (uz[y]==0) {
                    uz[y]=1;
                    q.push(y);
                }
            }
        }
    }
    if (d[i]==inf)
        return 0;
    return 1;
}
int fmcm()
{
    int i,k=0,o;
    do {
        o=bfs();
        k+=o*d[dest];
        if (o==0)
            break;
        for (i=dest;i;i=t[i]) {
            f[t[i]][i]++;
            f[i][t[i]]--;
        }

    }while (o);



    return k;
}


int main()
{
    ifstream fin("adapost.in");
    ofstream fout("adapost.out");
    fin>>n;
    int i,j;
    double kx,ky;
    for (i=1;i<=2*n;i++) {
        fin>>kx>>ky;
        p[i].x=kx*1000;p[i].y=ky*1000;
    }

    for (i=1;i<=n;i++)
        for (j=n+1;j<=2*n;j++)
            r[i][j]=dist(p[i],p[j]);


    int st=0,dr=1<<13,mid;

    while (st<=dr) {
        mid=(st+dr)>>1;
        make_graph(mid,0);
        if (solvesol(mid)) {
            sol=mid;
            dr=mid-1;
        }
        else
            st=mid+1;
    }
    dest=2*n+1;
    make_graph(mid,1);

    fout<<setprecision(3)<<fixed<<sol/1000.0<<' '<<fmcm()/1000.0<<'\n';

    return 0;
}
