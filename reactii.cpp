#define nmax 15005
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
int sti[nmax],sta[nmax],nr;

int comp(int p,int q)
{
    if (sta[p]+1==sti[q])
        return 1;
    if (sta[q]+1==sti[p])
        return 1;
    return 0;
}
int main()
{
    int i,j,p;
    freopen("reactii.in","r",stdin);
    freopen("reactii.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    for (i=1;i<=m;i++) {
        nr=0;
        for (j=1;j<=n;j++) {
            nr++;
            scanf("%d",&sti[nr]);
            sta[nr]=sti[nr];
            while (nr>1&&comp(nr-1,nr)==1) {
                nr--;
                sti[nr]=min(sti[nr],sti[nr+1]);
                sta[nr]=max(sta[nr],sta[nr+1]);
                sti[nr+1]=0;
                sta[nr+1]=0;
            }
        }
        if (nr==1)
            printf("1\n");
        else
            printf("0\n");
        }





return 0;
}
