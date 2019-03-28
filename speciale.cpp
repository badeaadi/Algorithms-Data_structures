#include <cstdio>
#define kmax 12
using namespace std;
int v[kmax*2],t[kmax];
int p,n,k,a,b;

int numarspecial(int x)
{
    int i;
    for (i=1;i<=18;i++)
        if (v[i]==x)
            return 1;
    return 0;
}
int main()
{
    int i,j,r,x;
    freopen("speciale.in","r",stdin);
    freopen("speciale.out","w",stdout);
    scanf("%d%d%d%d%d",&p,&k,&n,&a,&b);
    if (p==1) {
        for (i=9;i>=9-k+1;i--)
            printf("%d",i);
        return 0;
    }

    v[1]=1;v[2]=9;
    for (i=2;i<=9;i++) {
        v[2*i-1]=v[2*i-3]*10+i;
        v[2*i]=v[2*i-2]*10+(9-i+1);
    }
    if (p==2) {
        for (i=0;n;n/=10)
            t[++i]=n%10;
        for (r=i;r>=0;r--) {
            x=0;
            for (j=i;j>r;j--)
                x=x*10+t[j];
            for (j=r-1;j>=1;j--)
                x=x*10+t[j];
            if (numarspecial(x)) {
                printf("%d",x);
                return 0;
            }
        }
        printf("0");
        return 0;
    }
    j=0;
    for (i=1;i<=18;i++)
        if (v[i]>=a&v[i]<=b)
            j++;
    printf("%d",j);



    return 0;
}
