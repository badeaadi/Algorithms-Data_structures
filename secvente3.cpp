#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdio>
#define mmax 10005

using namespace std;

int a,b,p,m,sol[mmax];
long long k,l1,l2;
vector <pair <pair <long long,long long>,int > > q;

ifstream f("secvente3.in");
ofstream g("secvente3.out");

int main()
{
    int i,j,t;
    f>>a>>b>>p>>m;
    for (i=1;i<=m;i++) {
        f>>l1>>l2;
        q.push_back(make_pair(make_pair(l1-1,l2),i));
    }
    sort(q.begin(),q.end());
    t=k=a;
    for (i=0,j=1;i<m;j++) {
        while (i<m&&q[i].first.first==j)
            q[i++].first.first=k;
        t=(1LL*t*b)%p;
        k+=t;
    }
    for (i=0;i<m;i++) {
        q[i].first.first+=q[i].first.second;
        q[i].first.second=0;
    }
    sort(q.begin(),q.end());
    t=k=a;
    for (i=0,j=1;i<m;j++) {
        while (i<m&&k>q[i].first.first)
            sol[q[i++].second]=j-1;
        t=(1LL*t*b)%p;
        k+=t;
    }
    for (i=1;i<=m;i++)
        g<<sol[i]<<' ';

    return 0;
}
