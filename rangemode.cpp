#include <cstdio>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#define nmax 100005
#define sqmax 350
using namespace std;
ifstream f("rangemode.in");
ofstream g("rangemode.out");
vector <pair <pair <int,int > ,int > > p[sqmax+2];
int n,m,v[nmax],t[nmax];
int k,q,s[nmax];

void add(int i,int j)
{
    t[i]+=j;
    if (t[i]>t[k])
        k=i;
    if (t[i]==t[k]&&i<k)
        k=i;
}
int main()
{
    int i,j,o,w,a,b,b1;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>v[i];
    for (i=1;i<=m;i++) {
        f>>a>>b;
        if (b-a<=sqmax) {
            k=0;
            for (j=a;j<=b;j++)
                add(v[j],1);
            s[i]=k;
            for (j=a;j<=b;j++)
                add(v[j],-1);
        }
        else
            p[a/sqmax].push_back(make_pair(make_pair(b,a),i));
    }
    for (i=0;i<=n/sqmax;i++) {
        j=p[i].size();
        if (j==0)
            continue;
        sort(p[i].begin(),p[i].end());
        a=p[i][0].first.second;
        b=p[i][0].first.first;
        w=(i+1)*sqmax;
        k=0;
        for (j=w;j<=b;j++)
            add(v[j],1);
        q=k;
        for (j=a;j<w;j++)
            add(v[j],1);
        s[p[i][0].second]=k;
        k=q;
        for (j=a;j<w;j++)
            add(v[j],-1);

        for (j=1;j<p[i].size();j++) {
            a=p[i][j].first.second;
            b1=p[i][j].first.first;

            for (o=b+1;o<=b1;o++)
                add(v[o],1);
            b=b1;
            q=k;
            for (o=a;o<w;o++)
                add(v[o],1);
            s[p[i][j].second]=k;
            k=q;
            for (o=a;o<w;o++)
                add(v[o],-1);
        }
    }
    for (i=1;i<=m;i++)
        g<<s[i]<<'\n';
    return 0;
}
