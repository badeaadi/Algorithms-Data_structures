#include <fstream>
#include <ctime>
#include <iostream>
#include <cstdlib>
#define nmax 35
using namespace std;
ifstream f("badea.in");
ofstream g("badea.out");
const int t0[12][12]={
5,5,5,5,5,5,5,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,2,2,2,4,4,4,4,4,
3,3,3,3,1,1,1,1,1,1,1,1,
3,3,3,3,1,1,1,1,1,1,1,1,
};
const int t1[14][14]={
5,5,5,5,5,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
};
const int t2[20][20]={
5,5,5,5,5,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,2,2,2,4,4,4,4,4,4,4,4,4,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
3,3,1,1,1,1,1,1,1,1,1,1,1,1,
};
const int t3[16][16]={
6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,3,3,3,3,5,5,5,5,5,5,5,5,5,5,
4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};



const int t7[21][21]={
8,7,7,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,
8,7,7,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,
8,7,7,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,3,3,3,3,3,5,5,5,5,5,5,
8,7,7,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,
8,7,7,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,
8,7,7,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,
8,7,7,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,
8,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,
8,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,
8,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,
8,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,
};



int n,m,v[nmax][nmax],sol[nmax][nmax];
int k[nmax],fin;

void backs(int i,int j,int r)
{
    int p,q,l,c,ok;

    if (fin)
        return;


    if (j>m) {
        backs(i+1,1,r);
        return;
    }
    if (v[i][j]) {
        backs(i,j+1,r);
        return;
    }

    if (!r) {
        if (i>m) {
            for (p=1;p<=m;p++)
                for (q=1;q<=m;q++)
                    sol[p][q]=v[p][q];
            fin=1;
        }
        return;
    }

    for (p=m;p>=i;p--) {
        if (k[p-i+1])
            continue;
        k[p-i+1]=1;
        for (q=j;q<=m;q++) {
            if (k[q-j+1])
                continue;
            ok=1;
            for (l=i;l<=p&&ok;l++)
                for (c=j;c<=q&&ok;c++)
                    if (v[l][c])
                        ok=0;
            if (ok==0)
                continue;
            k[q-j+1]=1;
            for (l=i;l<=p;l++)
                for (c=j;c<=q;c++)
                    v[l][c]=r;
            backs(i,j+1,r-1);

            for (l=i;l<=p;l++)
                for (c=j;c<=q;c++)
                    v[l][c]=0;
            k[q-j+1]=0;
        }
        k[p-i+1]=0;
    }
}
int main()
{
    int i,j;
    srand(time(0));
    f>>n>>m;
    backs(1,1,n);
    g<<"const int c[21][21]={\n";
    for (i=1;i<=m;i++) {
        for (j=1;j<=m;j++)
            g<<sol[i][j]<<',';
        g<<'\n';
    }
    g<<"};";
    return 0;
}
