#include <cstdio>
#include <cstring>
#define nmax 15
using namespace std;
int n,m,v[nmax][nmax],pos[nmax][nmax];
int sol,s[nmax][nmax];


void regina(int l,int c,int val)
{
    int i,j;
    for (i=l,j=c;i>=1&&j>=1;i--,j--) //diagonala sus stanga
        pos[i][j]+=val;

    for (j=1;j<=l;j++) //linie
        pos[l][j]+=val;
    for (i=c;i<=n;i++) //coloana
        pos[i][c]+=val;

    for (i=l,j=c;i<=n&&j<=n;i++,j++) //diagonala jos dreapta
        pos[i][j]+=val;
}
void backing(int m)
{
    if (m>sol) {
        sol=m;
        memset(s,0,sizeof(s));
        memcpy(s,v,sizeof(v));
    }

    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            if (pos[i][j]==0) {
                v[i][j]=1;
                regina(i,j,1);
                backing(m+1);
                regina(i,j,-1);
                v[i][j]=0;
            }
}
void makeback()
{
    int i,j;

    backing(0);

    printf("%d\n",sol);
    for (i=1;i<=n;i++)
        for (j=1;j<=i;j++)
            if (s[i][j]==1)
                printf("%d %d\n",i,j);

}
int main()
{
    int i,j;
    freopen("regine.in","r",stdin);
    freopen("regine.out","w",stdout);

    scanf("%d",&n);
    if (n<=6)
        makeback();
    else {
        if (n%3==1||n%3==2) {
            m=(n/3)*2+1;
            printf("%d\n",m);
            if (n%3==1)
                n++;
            j=1;
            for (i=n-m;i<n;i++) {
                printf("%d %d\n",i,j);
                j+=2;
                if (j>m)
                    j=2;
            }
        }
        else {
            m=(n/3)*2;
            printf("%d\n",m);
            m++;n+=2;
            j=1;
            for (i=n-m;i<n-1;i++) {
                printf("%d %d\n",i,j);
                j+=2;
                if (j>m)
                    j=2;
            }
        }
    }


    return 0;
}
