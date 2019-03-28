#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
ifstream f("zc.in");
ofstream g("zc.out");
vector <pair<int,int> > l,c,vl,vc;
long long sol;
int n,m,x,y,w;
char p;

void put(int x,int y)
{
    if (x==0&&y==0)
        return;
    vl.push_back(make_pair(x,y));
    vc.push_back(make_pair(y,x));
}
void solve(vector <pair<int,int> > v,int a,int b1,int b2)
{
    int i,j,t;
    pair <int,int> p=make_pair(a,b1),q=make_pair(a,b2);

    for (j=-1,i=1<<20;i;i>>=1)
        if (j+i<w&&v[j+i]<p)
            j+=i;
    j++;
    if (j>=w)
        return;

    for (t=-1,i=1<<20q  ;i;i>>=1)
        if (t+i<w&&v[t+i]<=q)
            t+=i;

    if (v[t]<=q)
        sol+=t-j+1;
}
int main()
{
    int i,j,k;
    f>>n>>m;
    for (i=1;i<=n;i++) {
        f>>x>>y;f.get();
        put(x-2,y);
        for (j=y-1;j<=y+1;j++)
            put(x-1,j),put(x+1,j);
        for (j=y-2;j<=y+2;j++)
            put(x,j);
        put(x+2,y);
    }

    sort(vl.begin(),vl.end());
    l.push_back(vl[0]);
    for (i=1;i<vl.size();i++)
        if (vl[i]!=vl[i-1])
            l.push_back(vl[i]);


    sort(vc.begin(),vc.end());
    c.push_back(vc[0]);
    for (i=1;i<vc.size();i++)
        if (vc[i]!=vc[i-1])
            c.push_back(vc[i]);

    w=l.size();
    x=0,y=0;
    for (i=1;i<=m;i++) {
        f.get(p);f>>j;f.get();
        if (p=='N')
            solve(l,x,y+1,y+j),y+=j;
        if (p=='S')
            solve(l,x,y-j,y-1),y-=j;
        if (p=='E')
            solve(c,y,x+1,x+j),x+=j;
        if (p=='V')
            solve(c,y,x-j,x-1),x-=j;
    }
    g<<sol<<'\n';
    return 0;
}
