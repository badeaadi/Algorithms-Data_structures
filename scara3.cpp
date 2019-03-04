#include <fstream>
#define nmax 1205
#define kmax 1005
using namespace std;
ifstream f("scara3.in");
ofstream g("scara3.out");
int n,x,a[nmax],e[nmax];
pair <int,int> v[nmax];
pair <int,int> p;

int main()
{
    int i,j,k;
    f>>n;
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x;f>>a[x];
    }
    f>>k;
    for (i=1;i<=k;i++) {
        f>>x;f>>e[x];
    }
    for (i=2;i<=n;i++)
        v[i].first=v[i].second=1<<30;
    v[1].first=1;v[1].second=0;

    for (i=1;i<n;i++) {
        p.first=v[i].first+1;
        p.second=v[i].second;
        if (p<v[i+1])
            v[i+1]=p;

        for (j=i+1;j<=i+a[i]&&j<=n;j++) {
            p.first=v[i].first+1;
            p.second=v[i].second;
            if (p<v[j])
                v[j]=p;
        }
        for (j=i+1;j<=i+2*e[i]&&j<=n;j++) {
            p.first=v[i].first+1;
            p.second=v[i].second+(j-i+1)/2;
            if (p<v[j])
                v[j]=p;
        }
    }
    g<<v[n].first<<' '<<v[n].second<<'\n';

    return 0;
}
