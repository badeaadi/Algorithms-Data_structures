#include <cstdio>
#include <cstring>
#define nmax 205
#define lmax 5005
using namespace std;
int p,n,m,l[nmax],k[nmax];
char s[nmax][lmax];

void solvefirst()
{
    int i,j,maxsol=0;
    char sol[lmax]={0};
    for (i=1;i<=n;i++)
        if (l[i]>maxsol) {
            maxsol=l[i];
            strcpy(sol,s[i]);
        }
        else
            if (l[i]==maxsol)
                if (strcmp(s[i],sol)<0)
                    strcpy(sol,s[i]);
    printf("%s",sol);
}
int subsir(int a,int b)
{
    int i,j=0;
    for (i=0;i<l[b];i++) {
        while (j<l[a]&&s[a][j]!=s[b][i])
            j++;
        if (j<l[a])
            j++;
        else
            return 0;
    }
    return 1;
}
void solvesecond()
{
    int i,j;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            if (l[i]<l[j])
                if (subsir(j,i)) {
                    k[i]=1;
                    break;
                }
        if (k[i]==0)
            m++;
    }
    printf("%d\n",m);
    for (i=1;i<=n;i++)
        if (k[i]==0)
            printf("%s\n",s[i]);
}
int main()
{
    int i,j;
    freopen("interesant.in","r",stdin);
    freopen("interesant.out","w",stdout);
    scanf("%d %d\n",&p,&n);

    for (i=1;i<=n;i++) {
        scanf("%s\n",&s[i]);
        l[i]=strlen(s[i]);
    }
    if (p==1)
        solvefirst();
    else
        solvesecond();

    return 0;
}
