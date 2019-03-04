#include <bits/stdc++.h>
#define nmax 500
#define dmax 105
#define den 25
using namespace std;
int n,m,a,r,k,nrm,tot[nmax];
char s[nmax*dmax];
char h[25];
ifstream f("showroom.in");
ofstream g("showroom.out");
set <pair <char s[25],int t> >;

bool compmodels(const model &a,const model &b)
{
    int an=strlen(a.s);
    int bn=strlen(b.s);
    if (an!=bn)
        return an<bn;
    int i=0;
    while (a.s[i]&&a.s[i]==b.s[i])
        i++;
    return a.s[i]<b.s[i];
}

int main()
{
    int i,j,u;
    f>>n>>a>>r>>k;f.get();
    for (u=1;u<=n;u++) {
        f.getline(s,50000);
        m=strlen(s);
        i=0;t[u]=-1;
        while (s[i]==' ')
            i++;
        for (j=i;j<=m;j++)
            if (s[j]==' '||s[j]==0) {
                strncpy(v[++nrm].s,s+i,j-i);
                v[nrm].t=u;

                i=j+1;
                while (s[i]==' ')
                    i++,j++;
            }
    }



    for (i=1;i<=nrm;i++)
        if (t[i]<0)
            sol++;
    printf("%d\n",sol);

    return 0;
}



