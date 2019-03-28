#include <fstream>
#include <cstdio>
#define nmax 105
#define ucif 160
using namespace std;
ifstream f("sistem.in");
ofstream g("sistem.out");
int v[nmax][ucif+1],fact[nmax][ucif+1];
int n,aux[ucif+1],x[ucif+1];
int c[nmax][nmax][ucif+1];

void ver(int a[])
{
    for (int i=ucif;i>=1;i--)
        if (a[i]>9) {
            a[i-1]+=a[i]/10;
            a[i]%=10;
        }

}
void add(int a[],int b[])
{
    for (int i=1;i<=ucif;i++)
        a[i]+=b[i];
}
void prodx(int a[],int x)
{
    for (int i=1;i<=ucif;i++)
        a[i]*=x;
}

void prod(int a[],int b[])
{
    int i,j,i1,t=1;
    int x[ucif+1]={0};

    while (a[t]==0)
        t++;

    for (i=1;i<=ucif;i++) {
        i1=ucif-i;
        if (b[i]) {
            for (j=t;j<=ucif;j++)
                x[ucif-i1-(ucif-j)]+=b[i]*a[j];
        }
    }
    for (i=ucif;i>=1;i--)
        a[i]=x[i];

}


int main()
{
    int i,j;
    f>>n;
    for (i=0;i<=n;i++)
        for (j=0;j<=i;j++)
            if (i==j||j==0)
                c[i][j][ucif]=1;
            else {
                add(c[i][j],c[i-1][j]);
                add(c[i][j],c[i-1][j-1]);
                ver(c[i][j]);
            }
    fact[2][ucif]=1;

    for (i=3;i<=n;i++) {
        add(fact[i],fact[i-1]);
        prodx(fact[i],i);
        ver(fact[i]);
    }


    v[3][ucif]=1;
    for (i=4;i<=n;i++) {

        v[i][ucif]=1;
        prod(v[i],fact[i-1]);

        for (j=3;j<i;j++) {

            int aux[ucif+1]={0};
            add(aux,v[i-j]);

            prod(aux,c[i-1][j-1]);
            prod(aux,fact[j-1]);

            ver(aux);
            add(v[i],aux);
        }
        ver(v[i]);
    }
    i=1;
    while (v[n][i]==0)
        i++;
    for (;i<=ucif;i++)
        g<<v[n][i];

    return 0;
}
