#include <cstdio>
#include <fstream>
#include <algorithm>
#define nmax 20005
using namespace std;
FILE *f=fopen("arc.in","r");
ofstream g("arc.out");
int n,v[nmax];
int poz,lmax;

void secventamaxima(int p,int q)
{
    int i,j,x=0,l=0;
    lmax=0;poz=0;
    for (i=p;i<=q;i++)
        if (v[i]!=v[i-1]) {
            if (l>lmax) {
                lmax=l;
                poz=x;
            }
            x=i;l=1;
        }
        else
            l++;
        if (l>lmax) {
                lmax=l;
                poz=x;
            }
}

void solvea()
{
    int i,j=0;
    for (i=1;i<=n;i++)
        if (v[i]!=v[i-1])
            j++;
    g<<j<<'\n';
}
void solveb()
{
    int i,j,x=0,i1,j1;
    secventamaxima(1,n);
    while (lmax>=3) {
        for (i=poz;i<=n;i++) {
            v[i]=v[i+lmax];
            v[i+lmax]=0;
        }
        n-=lmax;
        if (n==0) break;
        i1=poz-1;j1=poz;
        if (v[i1]==v[j1]) {
            while (v[i1-1]!=0&&v[i1]==v[i1-1])
                i1--;
            while (v[j1+1]!=0&&v[j1]==v[j1+1])
                j1++;
            if (v[j1]==v[i1]&&j1-i1+1>=3) {
                poz=i1;
                lmax=j1-i1+1;
            }
                else
                secventamaxima(1,n);
        }
        else
            secventamaxima(1,n);
    }
    g<<n<<'\n';
    for (i=1;i<=n;i++)
        g<<v[i]<<'\n';

}

int main()
{
    int i,c;
    fscanf(f,"%d %d",&c,&n);
    for (i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    if (c==1)
        solvea();
    else
        solveb();

    return 0;
}
