#include <cstdio>
#include <vector>
#include <bitset>
#define nmax 100005
using namespace std;
int n,p,st,v[nmax],g[nmax],sol;
int a[nmax],b[nmax];
int k[nmax];

void next()
{
    for (;g[p];p++);
    if (p>n) {
        p=1;
        for (;g[p];p++);
    }
}
void dfs(int nod)
{
    if (k[nod]==1)
        return;
    k[nod]=1;
    if (k[v[nod]]==0)
        dfs(v[nod]);
    else {
        next();
        g[v[nod]]--;
        sol++;
        a[sol]=nod;b[sol]=p;

        v[nod]=p;
        g[v[nod]]++;
        dfs(p);
    }
}
int main()
{
    int i,j;
    freopen("telefon2.in","r",stdin);
    freopen("telefon2.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d",&v[i]);
        g[v[i]]++;
    }
    for (i=1;i<=n;i++)
        if (g[i]==0) {
            if (st==0)
                st=i;
            p=i+1;
            dfs(i);
            break;
        }
    st=1;
    for (i=1;i<=n;i++)
        if (k[i]==0) {
            if (b[sol])
                st=b[sol];
            b[sol]=i;
            j=i;
            k[i]=1;
            while (v[j]!=i) {
                j=v[j];
                k[j]=1;
            }
            sol++;
            a[sol]=j;
            b[sol]=st;
        }
    printf("%d\n",sol);
    for (i=1;i<=sol;i++)
        printf("%d %d\n",a[i],b[i]);
    return 0;
}
