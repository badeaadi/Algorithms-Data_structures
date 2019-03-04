
#include <fstream>
#include <algorithm>
#include <cstring>
#define nmax 50005
#define pmax 20
using namespace std;
ifstream f("aperm.in");
ofstream g("aperm.out");
int n,p,k,a[pmax];
long long fact[20];
char s[pmax * 5];
struct type {long long ord; int num;};
type v[nmax];

long long ordin()
{
    long long nr=0;
    int i,j;
    for (i=1;i<=p;i++) {
        nr+=1LL*(a[i]-1)*fact[p-i];
        for (j=i+1;j<=p;j++)
            if (a[j]>a[i])
                    a[j]--;
    }
    return nr+1;

}
bool compare(const type &x, const type &y)
{
    if (x.ord==y.ord)
        return x.num<y.num;
    return x.ord<y.ord;

}


int main()
{
    int i,j,x;
    f>>n>>p;f.get();
    fact[1]=1;
    for (i=2;i<20;i++) fact[i]=fact[i-1]*1LL*i;

    for (i=1;i<=n;i++) {
        f.getline(s,pmax *5);
        j=0;k=0;
        x=0;
        while (s[k]!=NULL) {
            if (s[k]==' ') {
                a[++j]=x;
                x=0;
            }
            else
                x=x*10+s[k]-'0';
            k++;
        }
        a[++j]=x;
       // if (i==3488||i==12218)
        v[i].ord=ordin();
        v[i].num=i;
        memset(s,0,sizeof(s));
    }
    sort(v+1,v+n+1,compare);
    for (i=1;i<=n;i++)
        g<<v[i].num<<'\n';

    return 0;
}
