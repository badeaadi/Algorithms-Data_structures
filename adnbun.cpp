#include<cstdio>
#include<cstring>
using namespace std;
int n5[19],s,j1,nr,mini,n3,n2,i,j,k,p,n[20],n1,phi[19][30002],d1[19][19],p1[19],cost[(1<<18)+1][19],d[19][19],n4[19],b[19],poz[19],ob[(1<<18)+1][19];
char a[19][30002];
int main()
{
freopen("adn.in","r",stdin);
freopen("adn.out","w",stdout);
scanf("%d\n",&n1);
for(i=1;i<=n1;i++)
{
    gets(a[i]+1);
    n[i]=strlen(a[i]+1);
    n5[i]=n[i];
    k=0;
    phi[i][1]=0;
    for(j=2;j<=n[i];j++)
    {
        while(k!=0&&a[i][k+1]!=a[i][j]) k=phi[i][k];
        if(a[i][k+1]==a[i][j]) k++;
        phi[i][j]=k;
    }
}
for(i=1;i<=n1;i++)
    for(j=1;j<=n1;j++)
    if(i!=j)
    {
        //ij
        //dc am i=aba si j=bac iese abac,d[i][j]=2(cat economiseste)
        k=0;
        for(p=1;p<=n[i];p++)
        {
            while(k!=0&&a[j][k+1]!=a[i][p]) k=phi[j][k];
            if(a[j][k+1]==a[i][p]) k++;
            if(k==n[j])
            {
                d1[i][j]=n[j];
                break;
            }
            if(p==n[i]) d1[i][j]=k;
        }
    }
n2=0;
for(i=1;i<=n1;i++)
    for(j=1;j<=n1;j++)
        if(d1[j][i]==n[i]) p1[i]=1;
for(i=1;i<=n1;i++)
    if(p1[i]==0)
    {
        n2++;
        n4[n2]=n[i];
        poz[n2]=i;
        n3=0;
        for(j=1;j<=n1;j++)
            if(p1[j]==0)
            {
                n3++;
                d[n2][n3]=d1[i][j];
            }
    }
n1=n2;
for(i=1;i<=n1;i++)
    n[i]=n4[i];
for(i=1;i<(1<<n1);i++)
    for(j=0;j<n1;j++)
        cost[i][j]=10000000;
for(i=0;i<n1;i++)
{
    cost[(1<<i)][i]=n[i+1];
    ob[(1<<i)][i]=0;
}
for(i=1;i<(1<<n1);i++)
    for(j=0;j<n1;j++)
        if(i&(1<<j))
        {
            for(k=0;k<n1;k++)
                if((i&(1<<k))==0)
                    if(cost[i+(1<<k)][k]>cost[i][j]+n[k+1]-d[j+1][k+1])
                    {
                        if((i+(1<<k))==7&&k==1)
                            k=1;
                        cost[i+(1<<k)][k]=cost[i][j]+n[k+1]-d[j+1][k+1];
                        ob[i+(1<<k)][k]=j;
                    }
        }
mini=10000000;
for(j=0;j<n1;j++)
    if(cost[(1<<n1)-1][j]<mini) mini=cost[(1<<n1)-1][j];
for(j=0;j<n1;j++)
    if(cost[(1<<n1)-1][j]==mini) break;
nr=n1+1;
s=(1<<n1)-1;
while(s!=0)
{
    nr--;
    b[nr]=poz[j+1];
    j1=j;
    j=ob[s][j];
    s=s-(1<<j1);
}
printf("%s",a[b[1]]+1);
for(i=2;i<=n1;i++)
    for(j=d1[b[i-1]][b[i]]+1;j<=n5[b[i]];j++)
        printf("%c",a[b[i]][j]);
//printf("%d\n",mini);
return 0;
}
