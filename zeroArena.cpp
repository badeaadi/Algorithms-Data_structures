#include <fstream>
#include <cstring>
#define nmax 205
#define lmax 22
using namespace std;
ifstream f("zero.in");
ofstream g("zero.out");
int p,q,l,b,aux[nmax];
int v[lmax][nmax],sol[nmax];

void suma(int a[],int b[],int k)
{
    int i;
    for (i=1;i<=b[0];i++)
        a[i]+=b[i]*k;

    a[0]=max(a[0],b[0])+5;

    for (i=1;i<=a[0];i++)
        if (a[i]>9) {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
        else
            while (a[i]<0) {
                a[i+1]--;
                a[i]+=10;
            }
    while (a[0]>=1&&a[a[0]]==0)
        a[0]--;
}
void prod(int a[],int k)
{
    int i;
    for (i=1;i<=a[0];i++)
            a[i]*=k;
    a[0]+=2;
    for (i=1;i<=a[0];i++)
        if (a[i]>9) {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    while (a[a[0]]==0)
        a[0]--;

}
void build(int k,int val)
{
    suma(v[1],aux,1);
    int i,j;
    for (i=2;i<=l;i++) {

        for (j=i-1;j>=1&&(i-j-1)<=k;j--) {
            suma(v[i],v[j],b-1);
        }
        if (l-i<=k)
            suma(sol,v[i],val);
    }
}
int main()
{
    int i;
    f>>l>>b>>p>>q;
    aux[0]=2;
    aux[1]=(b-1)%10;
    aux[2]=(b-1)/10;
    if (aux[2]==0)
        aux[0]--;

    build(p,1);
    for (i=sol[0];i>=1;i--) {
        g<<sol[i];
    }
    if (sol[0]==0)
        printf("0");
    g<<'\n';
    memset(v,0,sizeof(v));
    memset(sol,0,sizeof(sol));
    suma(sol,aux,1);
    for (i=1;i<l;i++)
        prod(sol,b);

    build(q-1,-1);

    if (sol[0]==0)
        printf("0");
    for (i=sol[0];i>=1;i--)
        g<<sol[i];

    return 0;
}
