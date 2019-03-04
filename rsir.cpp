#include <cstdio>
#define nmax 7005
using namespace std;
long long n;
int t0,t1,t2,a,b,x,y,z,m;
int l,s;
int mod1[nmax],mod2[nmax];


inline void next(int &p0,int &p1)
{
    //p2=(a*p0%m*p0%m + b*p1%m*p1%m + x*p0 + y*p1 +z)%m;
    int p2=mod1[p0]+mod2[p1];
    if (p2>=m)
        p2-=m;
    p0=p1;
    p1=p2;
}
int main()
{
    int i,j;
    freopen("rsir.in","r",stdin);
    freopen("rsir.out","w",stdout);
    scanf("%d %d",&t0,&t1);
    scanf("%d %d %d %d %d %d %lld",&a,&b,&x,&y,&z,&m,&n);
    for (i=0;i<=m;i++) {
        mod1[i]=a*i%m*i%m+x*i%m+z;
        mod1[i]%=m;
        mod2[i]=b*i%m*i%m+y*i%m;
        mod2[i]%=m;
    }
    if (n==0) {
        printf("%d\n",t0);
        return 0;
    }
    if (n==1) {
        printf("%d\n",t1);
        return 0;
    }
    int p0,p1,q0,q1;

    p0=t0%m;p1=t1%m;
    q0=t0%m;q1=t1%m;

    for (i=2,j=2;;i++,j+=2) {
        next(p0,p1);
        next(q0,q1);
        next(q0,q1);
        if (p0==q0&&p1==q1) {
            l=j-i+1;
            break;
        }
    }
    s=i;
    p0=t0%m;p1=t1%m;
    q0=t0%m;q1=t1%m;

    for (i=1;i<=l;i++)
        next(q0,q1);
    for (s=1;;s++) {
        if (p0==q0&&p1==q1)
            break;
        next(p0,p1);
        next(q0,q1);
    }
    p0=t0;p1=t1;
    s--;
    if (n<=s) {
        for (i=1;i<=n;i++)
            next(p0,p1);
    }
    else {
        n=s+(n-s)%l;
        for (i=1;i<=n;i++)
            next(p0,p1);
    }

    printf("%d\n",p0);

    return 0;
}
