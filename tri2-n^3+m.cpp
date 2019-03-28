//Solutie Badea Adrian problema tri2
//Solutie O(N^3+M) cu precalculare
#include <fstream>
#include <cstring>
#include <iostream>
#define nmax 1005
using namespace std;
ifstream f("tri2.in");
ofstream g("tri2.out");
struct punct{int x;int y;} v[nmax];
punct p,q;

int k[nmax][nmax],subp[nmax];
int n,m,str;
char s[15];

void getnumb(int &t)
{
    while (s[str]>='0'&&s[str]<='9')
        t=t*10+s[str++]-'0';
    str++;
}
inline int modul(int x)
{
    if (x<0)
        return -x;
    return x;
}
long long determinant(const punct &a,const punct &b,const punct &c)
{
    return 1LL*(1LL*b.x-a.x)*(1LL*c.y-a.y) - 1LL*(1LL*c.x-a.x)*(1LL*b.y-a.y);
}
long long arie(const punct &a,const punct &b,const punct &c)
{
    long long t=1LL*(1LL*b.x-a.x)*(1LL*c.y-a.y) - 1LL*(1LL*c.x-a.x)*(1LL*b.y-a.y);
    if (t<0)
        return -t;
    return t;
}
inline int mijloc(const int &a,const int &b,const int &c)
{
    if (v[a].x<=v[b].x&&v[b].x<=v[c].x)
        return 1;
    return 0;
}
int sub(const punct &a,const punct &b,const punct &c)
{
    long long ari=arie(c,a,b)+arie(c,b,q)+arie(c,q,p)+arie(c,p,a);
    if (ari==arie(p,a,b)+arie(p,q,b))
        return 1;
    return 0;


}
int main()
{
    int i,j,t,x,y,z,minx,maxx,sol1,sol2;
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,15);
        str=0;
        getnumb(v[i].x);getnumb(v[i].y);
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (v[i].x==v[j].x&&v[j].y<v[i].y)
                subp[i]++;
    for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++) {
            //Cautam pentru fiecare din cele n^2 segmente cate puncte sunt sub fiecare dintre ele
            minx=min(v[i].x,v[j].x);
            maxx=max(v[i].x,v[j].x);
            x=i;y=j;
            if (v[y].x<v[x].x)
                swap(x,y);
            p=v[x];q=v[y];
            p.y=0;q.y=0;
            for (t=1;t<=n;t++)
                if (t!=i&&t!=j&&minx<=v[t].x&&v[t].x<=maxx&&sub(v[x],v[y],v[t])) {
                    k[i][j]++;
                    k[j][i]++;
                }
    }
    f>>m;f.get();
    for (i=1;i<=m;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,15);
        str=0;
        x=0;y=0;z=0;
        getnumb(x);getnumb(y);getnumb(z);
            //S-a format un triunghi al carui punct dintre cele doua il setez ca fiind x
        if (mijloc(x,y,z)||mijloc(z,y,x))
            swap(y,x);
        if (mijloc(x,z,y)||mijloc(y,z,x))
            swap(z,x);
        if (x==y||x==z||y==z)
            continue;

        sol1=k[z][y]-k[x][y]-k[x][z]-1+subp[x];
        sol2=k[x][y]+k[x][z]-k[y][z]-subp[x];

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
