#include <fstream>
#include <cstdio>
#include <deque>
#define nmax 100005
#define kmax 32
using namespace std;
ifstream f("secvbest.in");
ofstream g("secvbest.out");
deque <int> p,q;
int v[kmax][nmax];
int a[nmax],s[nmax];

int main()
{
    int i,j;
    f>>n>>k>>t;
    for (i=1;i<=n;i++) {
        f>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (j=1;j<=n;j++)
        v[1][j]=max(t-s[j],s[j]-t);

    for (i=2;i<=k;i++) {
        p.clear();q.clear();
        for (j=i-1;j<n;j++) {
            while (!p.empty()&&v[i-1][j]+t-a[j+1]<v[i-1][p.back()]+t-s[j+1]-s[p.back()])
                p.pop();

        }
    }
    return 0;
}
