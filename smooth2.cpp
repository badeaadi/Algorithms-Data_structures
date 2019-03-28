#include <fstream>
#include <cstring>
#include <algorithm>
#define nmax 100035
#define teta 26
using namespace std;
ifstream f("smooth2.in");
ofstream g("smooth2.out");
char s[nmax];
int n,m,v[teta+50],o[teta+50];
int k[teta+50],sol=1<<30;

struct cost{int cost;int ind;} c[teta];

int sortcomp(const cost &a,const cost &b)
{
    return a.cost>b.cost;
}
int verify(int p)
{
    int j,t,co=0;
    for (j=0;j<n;j++) {
        k[s[j]-'a']++;
        if ((j+1)%p==0) {
            for (t=0;t<teta;t++)
                if (o[t]&&k[t]==0)
                    co++;
                else
                    k[t]=0;
            }
        }
    for (t=0;t<teta;t++)
        if (k[t]&&o[t]==0) {
            co+=k[t];
            k[t]=0;
        }

    for (t=0;t<teta;t++)
        if (k[t]>=2)
            co+=k[t]-1;

    return co;
}
int main()
{
    int i,j,t,p;
    f.getline(s,nmax);
    n=strlen(s);
    for (i=0;i<n;i++)
        v[s[i]-'a']++;

    for (t=0,m=0;t<teta;t++)
        if (v[t])
            c[++m].ind=t+1;

    for (i=0;i<teta;i++)
        if (v[i])
            o[i]=1;
    sol=min(sol,verify(m));
    memset(k,0,sizeof(k));

    for (i=1;i<m;i++) {

        for (t=0,m=0;t<teta;t++)
            if (v[t])
                c[++m].ind=t+1;

        for (j=0;j<n;j++) {
            k[s[j]-'a']++;
            if ((j+1)%(m-i)==0) {
                for (t=0;t<teta;t++)
                    if (v[t]&&k[t]==0) {
                        for (p=0;p<teta;p++)
                            if (c[p].ind==t+1)
                                c[p].cost++;
                    }
                    else
                        k[t]=0;
            }
        }
        for (t=0;t<teta;t++)
            if (k[t])
                c[t+1].cost--;
        memset(k,0,sizeof(k));
        sort(c+1,c+m+1,sortcomp);
        for (t=0;t<teta;t++)
            if (v[t])
                o[t]=1;
        for (t=1;t<=i;t++)
            o[c[t].ind-1]=0;

        sol=min(sol,verify(m-i));
    }
    g<<sol<<'\n';
    return 0;
}
