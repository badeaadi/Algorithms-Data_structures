//Solutie Badea Adrian problema tri2
//Solutie O(N*M) brute-force
#include <fstream>
#include <cstring>
#define nmax 1005
using namespace std;
ifstream f("tri2.in");
ofstream g("tri2.out");
struct punct{int x;int y;} v[nmax];
int k[nmax][nmax],sol;
int n,m,str;
char s[15];

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
long long arie(const punct &a,const punct &b,const punct &c)
{
    long long p=determinant(a,b,c);
    if (p<0)
        return -p;
    return p;
}
int main()
{
    int i,j,t,x,y,z,minx,maxx;
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,15);
        str=0;
        getnumb(v[i].x);getnumb(v[i].y);
    }
    f>>m;f.get();
    for (j=1;j<=m;j++) {
        memset(s,0,sizeof(s));
        f.getline(s,15);
        str=0;
        x=0;y=0;z=0;
        getnumb(x);getnumb(y);getnumb(z);
        sol=0;
        if (x==y||y==z||x==z)
            continue;
        for (i=1;i<=n;i++)
            if (x!=i&&y!=i&&z!=i) {
                if (1LL*arie(v[x],v[y],v[i])+arie(v[x],v[z],v[i])+arie(v[y],v[z],v[i])==1LL*arie(v[x],v[y],v[z])) {
                        sol++;
                        if (determinant(v[i],v[x],v[y])==0||determinant(v[i],v[y],v[z])==0||determinant(v[i],v[x],v[z])==0)
                            sol--;
                    }
            }
        g<<sol<<'\n';
    }
    return 0;
}
