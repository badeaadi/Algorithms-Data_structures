#include <fstream>
#define nmax 30000
using namespace std;
ifstream f("armonica.in");
ofstream g("armonica.out");
long long c,x[nmax],y[nmax];
int a,b,sol,d[nmax],e[nmax],de;



void veri(long long a)
{
    if (a>=b)
        return;
    if ((1LL*a*b)%(2*a-b)==0) {
        sol++;
        x[sol]=a;
        y[sol]=(1LL*a*b)/(2*a-b);
    }
}
void gendiv(int t,long long k)
{
    if (t>de) {
        if (b%2==0)
            veri(b/2+k);
        else
            veri(b/2+(k+1)/2);
        return;
    }
    int i;
    gendiv(t+1,k);
    for (i=0;i<e[t];i++) {
        k*=d[t];
        gendiv(t+1,k);
    }
}
int main()
{
    int i,j;
    f>>b;
    i=2;j=b;
    while (j!=1) {
        if (j%i==0) {
            d[++de]=i;
            j/=i;
            e[de]=2;
            while (j%i==0)
                e[de]+=2,j/=i;
        }
        else
            if (i*i>j) {
                d[++de]=j;
                e[de]=2;
                break;
            }
        i++;
    }
    gendiv(1,1);
    g<<2*sol+1<<'\n';
    g<<b<<' '<<b<<'\n';
    for (i=1;i<=sol;i++) {
        g<<x[i]<<' '<<y[i]<<'\n';
        g<<y[i]<<' '<<x[i]<<'\n';
    }
    return 0;
}
