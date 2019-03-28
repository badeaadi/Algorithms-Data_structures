#include <fstream>
#include <cstring>
#include <algorithm>
#define inf 1<<30
#define nmax 5005
using namespace std;
ifstream f("tst.in");
ofstream g("tst.out");
long long sol;
struct suffix{int x;int p;} v[nmax];
char s[nmax];
int n,m;

int sortcomp(const suffix &a,const suffix b)
{
    if (a.x!=b.x)
        return a.x<b.x;
    return a.p<b.p;

}
int main()
{
    int i,j,t,k,a,b;
    f.getline(s,nmax);
    n=strlen(s);
    for (i=0;i<n;i++) {
        v[i].x=s[i]-'a';
        v[i].p=i;
    }
    for (i=0;i<n;i++) {
        sort(v,v+n,sortcomp);
        v[n].x=inf;
        m=0;
        for (j=0;j<n;j++) {
            if (v[j].x==inf)
                continue;
            t=j;
            while (v[j].x==v[t+1].x)
                t++;
            m++;
            for (k=j;k<=t;k++)
                v[k].x=m;
            j=t;
        }

        for (j=0;j<n;j++) {
            if (v[j].x==inf)
                break;
            t=j;
            while (v[j].x==v[t+1].x)
                t++;
            if (t==j) {
                sol+=1LL*(v[j].p+1)*(n-v[j].p-i);
                continue;
            }
            for (k=j;k<t;k++) {

                a=v[k].p+1;

                b=v[k+1].p-v[k].p;

                sol+=1LL*a*b;
            }
            a=v[t].p+1;
            b=n-v[k].p-i;
            sol+=1LL*a*b;
            j=t;
        }
        for (j=0;j<n;j++) {
            if (v[j].p+i+1<n)
                v[j].x=v[j].x*26+s[v[j].p+i+1]-'a';
            else
                v[j].x=inf;
        }
    }
    g<<sol<<'\n';
    return 0;
}
