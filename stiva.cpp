#include <cstdio>
#include <cstring>
#include <algorithm>
#define nmax 505
using namespace std;
int n,v[nmax][nmax];
char s[nmax];

int main()
{
    freopen("stiva.in","r",stdin);
    freopen("stiva.out","w",stdout);
    scanf("%s",&s);
    int i,j,t,k;
    n=strlen(s);
    for (i=0;i<n;i++)
        v[i][i]=1;
    for (t=1;t<=n;t++)
        for (i=0;i+t<n;i++) {
            j=i+t;
            v[i][j]=v[i][j-1]+1;
            for (k=i;k<=j-1;k++)
                if (s[k]==s[j])
                    v[i][j]=min(v[i][j],v[i][k]+v[k+1][j-1]);
        }
    printf("%d\n",v[0][n-1]*2+n);

    return 0;
}
