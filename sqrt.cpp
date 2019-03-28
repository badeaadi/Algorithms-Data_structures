#include <fstream>
#define nmax 2100
#define sqr 60
using namespace std;
ifstream f("sqrt.in");
ofstream g("sqrt.out");
int n,k,st[sqr],dr[sqr];
int v[nmax],aux[nmax];

int mic(int a[],int b[])
{
    if (a[0]!=b[0])
        return a[0]<b[0];
    i=1;
    while (i<=a[0]&&a[i]==b[i])
        i++;
    return (a[i]<b[i]);

}

int main()
{
    f>>n>>k;
    v[0]=2*k+30;
    while (n) {
        v[++v[0]]=n%10;
        n/=10;
    }
    st[0]=st[1]=1;
    dr[0]=dr[sqrt(1.0*k)+5]=1;
    while (mic(st,dr)) {
        clearing(mid);
        sum(mid,st);
        sum(mid,dr);
        split(mid,2);
        clearing(aux);
        sum(aux,mid);
        prod(aux,mid);
        if (mic(aux,v)) {

        }
    }
    return 0;
}
