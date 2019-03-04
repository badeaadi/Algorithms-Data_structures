#include <cstdio>
#define nmax 22
#define mod 666013
using namespace std;
int n,m;
int v[nmax][nmax];
long long sol;

int searching(int l1,int c1,int l2,int c2)
{
    int i,j;
    if ((l1+l2)%2==0&&(c1+c2)%2==0)
        return 1-v[(l1+l2)/2][(c1+c2)/2];
    return 0;
}
void backing(int k,int l,int c)
{
    //sol+1==mod?printf("%d\n",sol),sol==0:sol++;
    sol++;
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            if (v[i][j]==0&&searching(l,c,i,j)==0) {
                v[i][j]=k+1;
                backing(k+1,i,j);
                v[i][j]=0;
            }
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
        for (j=0;j<m;j++) {
            v[i][j]=1;
            backing(1,i,j);
            v[i][j]=0;
        }
    printf("%lld",sol);

    return 0;
}
