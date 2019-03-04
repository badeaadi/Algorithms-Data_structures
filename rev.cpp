#include <cstdio>
#include <algorithm>
#define nmax 100005
#define sqrtmax 500
using namespace std;
int a[sqrtmax],b[sqrtmax],k;
int n,m,v[nmax],r[nmax];

void split(int t)
{
    int i,j,l,z;
    for (i=1;i<=k&&t>0;i++) {
        l=max(a[i],b[i])-min(a[i],b[i])+1;
        if (t-l<0) {
            for (j=k+1;j>=i+2;j--) {
                a[j]=a[j-1];a[j-1]=0;
                b[j]=b[j-1];b[j-1]=0;
            }
            k++;
            if (a[i]<b[i]) {
                z=a[i]+t-1;
                a[i+1]=z+1;
                b[i+1]=b[i];
                b[i]=z;
            }
            else {
                z=a[i]-t+1;
                a[i+1]=z-1;
                b[i+1]=b[i];
                b[i]=z;
            }
            break;
        }
        else
            t-=l;
    }
}
int main()
{
    int i,j,t,l,p;
    int x,y,q;
    freopen("rev.in","r",stdin);
    freopen("rev.out","w",stdout);
    scanf("%d %d",&n,&m);
    a[1]=1;b[1]=n;
    k=1;
    for (i=1;i<=n;i++)
        v[i]=i;
    for (;m;m--) {
        scanf("%d %d %d",&x,&y,&q);
        split(x-1);
        split(y);

        p=0;
        for (i=1,t=1<<30,l=-(1<<30);i<=k;i++) {
            p=max(a[i],b[i])-min(a[i],b[i])+1;
            x-=p;y-=p;
            if (x<1&&y>=0) {
                swap(a[i],b[i]);
                t=min(t,i);
                l=max(l,i);
            }
        }

        for (i=t,j=l;i<j;i++,j--) {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
        }
        for (i=1;i<=k;i++) {
            p=max(a[i],b[i])-min(a[i],b[i])+1;
            if (q-p<=0) {
                if (a[i]<b[i])
                    printf("%d\n",v[a[i]+q-1]);
                else
                    printf("%d\n",v[a[i]-q+1]);
                break;
            }
            q-=p;
        }
        if (k+5>sqrtmax) {
            n=0;
            for (i=1;i<=k;i++)
                if (a[i]<b[i])
                    for (j=a[i];j<=b[i];j++)
                        r[++n]=v[j];
                else
                    for (j=a[i];j>=b[i];j--)
                        r[++n]=v[j];
            for (i=1;i<=n;i++)
                v[i]=r[i];


            a[1]=1;b[1]=n;
            k=1;
        }
    }

    return 0;
}
