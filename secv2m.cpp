#include <cstdio>
#include <deque>
#define nmax 2005
using namespace std;
deque <pair <int,int > > d;
int a[nmax],b[nmax];
int n,m,l;


void solve(int &sol,int &p,int &q)
{
    int i,j,k,t;
    sol=1<<30;
    for (i=1;i<=n-l+1;i++) {
        d.clear();
        for (j=1,t=i;t<=n&&j<=m;j++,t++) {
            if (j>=l+1&&d.front().first<sol) {
                sol=d.front().first;
                p=t-l;
                q=j-l;
            }
            if (d.front().second==j-l)
                d.pop_front();
            k=a[t]+b[j];
            while (!d.empty()&&k>=d.back().first)
                d.pop_back();
            d.push_back(make_pair(k,j));
        }
        if (d.front().first<sol) {
            sol=d.front().first;
            p=t-l;
            q=j-l;
        }
    }
}
int main()
{
    int i;
    freopen("secv2m.in","r",stdin);
    freopen("secv2m.out","w",stdout);
    scanf("%d %d %d",&n,&m,&l);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int sol1,p1,q1;
    solve(sol1,p1,q1);

    swap(n,m);
    for (i=1;i<=max(n,m);i++)
        swap(a[i],b[i]);

    int sol2,p2,q2;
    solve(sol2,p2,q2);

    if (sol1<sol2)
        printf("%d\n%d %d\n",sol1,p1,q1);
    else
        printf("%d\n%d %d\n",sol2,q2,p2);

    return 0;
}
