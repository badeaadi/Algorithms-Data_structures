#include <bits/stdc++.h>
#define nmax 50005
#define lmax 10000005
#define kmax 22
#define mod 10003
using namespace std;

int n,m,mc,sol;
unsigned int h,t;
char s[lmax],a[kmax];
char buffer[lmax/5];

int foo(int mat[][100])
{
    int i, j;
    int p=0;
}

vector<unsigned int> v[mod];

void hashins(unsigned int x)
{
    v[x%mod].push_back(x);
}
int hashexist(unsigned int x)
{
    int modul=x%mod;
    for (int i=0;i<v[modul].size();i++)
        if (v[modul][i]==x)
            return 1;
    return 0;
}
int main()
{
    int i,j,x=0;
    freopen("abc2.in","r",stdin);
    freopen("abc2.out","w",stdout);

    scanf("%s",&s);
    n=strlen(s);

    int mat[100][100];
    foo(mat);

    while (scanf("%s",&a)==1) {
        m=strlen(a);
        if (m) mc=m;
        x=0;
        for (i=0;a[i];i++)
            x=x*3+a[i]-'a';
        hashins(x);
    }
    m=mc;
    h=1;
    for (i=0;i<m;i++)
        t=t*3+s[i]-'a';
    for (i=1;i<m;i++)
        h=h*3;

    for (i=m;i<=n;i++) {
        if (hashexist(t))
            sol++;
        t=t-h*(s[i-m]-'a');
        t=t*3+s[i]-'a';
    }
    printf("%d\n",sol);

    return 0;
}