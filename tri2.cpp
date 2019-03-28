//Solutie Badea Adrian problema tri2
//Solutie O(N^2*log (n) +M) cu precalculare
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>
#define ub(i) i&(-i)
#define nmax 1005
using namespace std;
ifstream f("tri2.in");
ofstream g("tri2.out");
struct punct{int x;int y;int ord;} v[nmax],v1[nmax];
punct p,q;
int k[nmax][nmax],subp[nmax],tot[nmax];
int n,m,str,aib[nmax];
char s[25];
struct punct2{int x;int y;int ord;};
punct2 w[nmax];
int nr,nr1,norm[nmax],poz[nmax];


void update(int poz,int x)
{
    for (;poz<=nmax;poz+=ub(poz))
        aib[poz]+=x;
}
int query(int poz)
{
    int sum=0;
    for (;poz>=1;poz-=ub(poz))
        sum+=aib[poz];
    return sum;
}
bool comparepoints(const punct2 &a,const punct2 &b)
{
    return (1.0*a.y/a.x)<(1.0*b.y/b.x);
}
bool comparepuncte(const punct &a,const punct &b)
{
    return a.x<b.x;

}
void getnumb(int &t)
{
    while (s[str]>='0'&&s[str]<='9')
        t=t*10+s[str++]-'0';
    str++;
}
long long determinant(const punct &a,const punct &b,const punct &c)
{
    return 1LL*(1LL*b.x-a.x)*(1LL*c.y-a.y) - 1LL*(1LL*c.x-a.x)*(1LL*b.y-a.y);
}
inline int mijloc(const int &a,const int &b,const int &c)
{
    if (v1[a].x<=v1[b].x&&v1[b].x<=v1[c].x)
        return 1;
    return 0;
}
int main()
{
    int i,j,t,x,y,z,minx,maxx,sol1,sol2;
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,25);
        str=0;
        getnumb(v[i].x);getnumb(v[i].y);
        v[i].ord=i;
    }
    for (i=1;i<=n;i++)
        v1[i]=v[i];
    sort(v+1,v+n+1,comparepuncte);

    for (i=1;i<=n;i++) {
        nr=0;
        for (j=1;j<=n;j++)
            if (v[i].x<v[j].x) {
                nr++;
                w[nr].x=v[j].x-v[i].x;
                w[nr].y=v[j].y-v[i].y;
                w[nr].ord=v[j].ord;
            }
        sort(w+1,w+nr+1,comparepoints);
        nr1=0;
        for (j=1;j<=nr;j++)
            norm[++nr1]=w[j].x;
        sort(norm+1,norm+nr+1);
        for (j=1;j<=nr;j++)
            if (norm[j]==norm[j-1])
                poz[j]=poz[j-1];
            else
                poz[j]=poz[j-1]+1;
        int st,dr,mid,sol;

        for (j=1;j<=nr;j++) {
            st=1;dr=nr;
            sol=0;
            while (st<=dr) {
                mid=(st+dr)>>1;
                if (norm[mid]<=w[j].x) {
                    sol=poz[mid];
                    st=mid+1;
                }
                else
                    dr=mid-1;
            }
            w[j].x=sol;
        }
        for (j=1;j<=nr;j++) {
            t=query(w[j].x);
            k[v[i].ord][w[j].ord]+=t;
            k[w[j].ord][v[i].ord]+=t;
            update(w[j].x,1);
        }
        for (j=0;j<nmax;j++)
            aib[j]=0;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (v[i].x==v[j].x&&v[j].y<v[i].y)
                subp[i]++;
    f>>m;f.get();
    for (i=1;i<=m;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,25);
        str=0;
        x=0;y=0;z=0;
        getnumb(x);getnumb(y);getnumb(z);
        if (mijloc(x,y,z)||mijloc(z,y,x))
            swap(y,x);
        if (mijloc(x,z,y)||mijloc(y,z,x))
            swap(z,x);
        if (x==y||x==z||y==z)
            continue;

        sol1=k[z][y]-k[x][y]-k[x][z]-1;
        sol2=k[x][y]+k[x][z]-k[y][z];

        if (sol1<0) {
            g<<sol2<<'\n';
            continue;
        }
        if (sol2<0) {
            g<<sol1<<'\n';
            continue;
        }
        if (v[x].y<=v[y].y&&v[x].y<=v[z].y)
            g<<sol1<<'\n';
        else
            g<<sol2<<'\n';
    }
    return 0;
}
