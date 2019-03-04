#include <cstdio>
#include <cstring>
#include <algorithm>
#define nmax 16005
#define mil 32000
#define inf 1<<30
using namespace std;
int heap[mil+5],poz[mil+5],nrp;
int d[mil+5],na,nb,nc;
char a[nmax],b[nmax],c[nmax];


inline int modul(int x)
{
    if (x<0)
        return -x;
    return x;
}
void heapup(int x)
{
    while (x>1&&d[heap[x]]<d[heap[x/2]]) {
        swap(poz[heap[x]],poz[heap[x/2]]);
        swap(heap[x],heap[x/2]);
        x/=2;
    }
}
void heapdown(int x)
{
    int fiu;
    do
    {
        fiu=0;
        if (x*2<=nrp&&d[heap[x*2]]<d[heap[x]])
            fiu=x*2;
        if (x*2+1<=nrp&&d[heap[x*2+1]]<d[heap[x]]&&d[heap[x*2+1]]<d[heap[2*x]])
            fiu=x*2+1;
        if (fiu) {
            swap(poz[heap[fiu]],poz[heap[x]]);
            swap(heap[fiu],heap[x]);
            x=fiu;
        }

    } while (fiu);

}
inline void ver(int x,int y)
{
    if (x<0||x>mil)
        return;
    if (d[x]>y) {
        d[x]=y;
        if (!poz[x]) {
            poz[x]=++nrp;
            heap[nrp]=x;
        }
        heapup(poz[x]);
    }
}
int main()
{
    freopen("base3.in","r",stdin);
    freopen("base3.out","w",stdout);
    int i,j,x;
    scanf("%s\n%s\n%s",&a,&b,&c);
    na=strlen(a);nb=strlen(b);nc=strlen(c);
    for (i=0;i<=mil;i++)
        d[i]=1<<30;
    for (i=0;a[i];i++)
        if (a[i]=='1')
            ver(modul((na-1-i)-i),na);

    for (i=0;b[i];i++)
        if (b[i]=='1')
            ver(modul((nb-1-i)-i),nb);

    for (i=0;c[i];i++)
        if (c[i]=='1')
            ver(modul((nc-1-i)-i),nc);
    while (nrp) {
        x=heap[1];
        if (x==0) {
            printf("%d\n",d[0]);
            return 0;
        }
        poz[x]=-1;
        heap[1]=heap[nrp];
        heap[nrp--]=0;
        if (nrp)
            poz[heap[1]]=1;
        heapdown(1);

        ver(x+na,d[x]+na);ver(x-na,d[x]+na);
        ver(x+nb,d[x]+nb);ver(x-nb,d[x]+nb);
        ver(x+nc,d[x]+nc);ver(x-nc,d[x]+nc);
    }
    printf("0\n");
    return 0;
}
