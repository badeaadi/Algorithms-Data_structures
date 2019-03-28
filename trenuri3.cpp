#include <fstream>
#include <cstdio>
#include <set>
#include <algorithm>
#define nmax 100005
#define x first
#define y second
#define dist x.x
#define extra x.y
#define type y.x
#define index y.y
using namespace std;
ifstream f("trenuri3.in");
ofstream g("trenuri3.out");
pair <int,int>  v[nmax];
pair <pair <int,int> , pair <int,int > > e[3*nmax];
int n,m,k,c,now;
int sol,t[nmax];

class cmpset
{
    public:
        bool operator()(const int& a,const int& b) {
            if(v[a].x==v[b].x)
                return a<b;
            return v[a].x<v[b].x;
        }
};
set<int,cmpset> s;
multiset<int> w;

int cmp(const pair <pair <int,int> , pair <int,int > > &a, const pair <pair <int,int> , pair <int,int > > &b)
{
    if(a.dist==b.dist){
        if(a.type==b.type)
            return a.extra>b.extra;
        return a.type<b.type;
    }
    return a.dist>b.dist;
}
int main ()
{
    int i,a,b,p,q;
    f>>n>>m;
    for(i=1;i<=n;i++) {
        f>>a>>b;
        e[++k]=make_pair(make_pair(a,b),make_pair(0,i));
    }
    for(i=1;i<=m;i++) {
        f>>a>>b;
        e[++k]=make_pair(make_pair(a,1),make_pair(1,i));
        e[++k]=make_pair(make_pair(b,0),make_pair(1,i));
        v[i]=make_pair(a,b);
    }
    sort(e+1,e+k+1,cmp);

    for(i=1;i<=k;i++) {
        if(e[i].type==0) {
            p=c;
            c+=e[i].extra;
            if (c>m)
                c=m;
            p=c-p;
            while(p) {
                w.insert(e[i].index);
                p--;
            }
            continue;
        }
        if(e[i].extra==0) {
            if(now<c) {
                now++;
                t[e[i].index]=*w.begin();
                w.erase(w.begin());
                s.insert(e[i].index);
            }
            else {
                q=*s.begin();
                if(v[e[i].index].x>v[q].x) {
                    t[e[i].index]=t[q];
                    t[q]=0;
                    s.erase(q);
                    s.insert(e[i].index);
                }
            }
        }
        else
        {
            if(!t[e[i].index])
                continue;
            sol++;
            now--;
            s.erase(e[i].index);
            w.insert(t[e[i].index]);
        }
    }
    g<<sol<<'\n';
    for(i=1;i<=m;i++)
        g<<t[i]<<'\n';
    g<<'\n';
    return 0;
}
