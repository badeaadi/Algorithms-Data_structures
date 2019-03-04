#include <cstdio>
#define nmax 5005
using namespace std;
char s[nmax],a,b,p[300];
char k[nmax],t[300],r[300];
int m,n;

int solve()
{
    int i;
    for (i='a';i<='z';i++)
        r[i]=0;
    for (i=0;k[i];i++)
        r[k[i]]++;
    for (i='a';i<='z';i++)
        if (t[i]!=r[i])
            return 0;

    for (i=0;s[i];i++)
        if ((s[i]=='a'&&k[i]!='a')||(k[i]=='a'&&s[i]!='a'))
            return 0;

    for (i=0;s[i];i++)
        if (s[i]!=k[i]&&s[i]!=p[k[i]])
            return 0;
    return 1;
}
int main()
{
    freopen("ar.in","r",stdin);
    freopen("ar.out","w",stdout);
    scanf("%s\n%d %d\n",&s,&m,&n);
    int i;
    for (i=0;s[i];i++)
        t[s[i]]++;
    for (i=1;i<=m;i++) {
        scanf("%c %c\n",&a,&b);
        p[a]=b;p[b]=a;
    }
    for (i=1;i<=n;i++) {
        scanf("%s\n",&k);
        if (solve())
            printf("%d\n",i);
    }
    return 0;
}
