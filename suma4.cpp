#include <cstdio>
#include <fstream>
#define u 58
using namespace std;
FILE *f=fopen("suma4.in","r");
FILE *g=fopen("suma4.out","w");
int v[u][u][u],t[u][u][u],d[u][u][u];
int niv,minim,pos,p;
int a[70000],sol[70];


int main()
{int k,i,j,n,l;

fscanf(f,"%d",&n);
l=n;
while (l>=niv*niv) {l-=niv*niv;
                    niv++;
                    }
niv--;
fprintf(g,"%d ",niv);
for (k=1;k<=niv;k++)
            for (i=1;i<=k;i++) for (j=1;j<=k;j++)
                    {++p;
                     t[k][i][j]=p;
                     fscanf(f,"%d",&v[k][i][j]);
                     }
d[1][1][1]=v[1][1][1];
for (k=2;k<=niv;k++)
           for (i=1;i<=k;i++) for (j=1;j<=k;j++)
                    {minim=1<<26;

                     if (i-1>=1&&j-1>=1&&i-1<=k-1&&j-1<=k-1&&d[k-1][i-1][j-1]<minim)
                                              minim=d[k-1][i-1][j-1],pos=t[k-1][i-1][j-1];

                     if (i-1>=1&&j>=1&&i-1<=k-1&&j<=k-1&&d[k-1][i-1][j]<minim)
                                            minim=d[k-1][i-1][j],pos=t[k-1][i-1][j];

                     if (i>=1&&j-1>=1&&i<=k-1&&j-1<=k-1&&d[k-1][i][j-1]<minim)
                                            minim=d[k-1][i][j-1],pos=t[k-1][i][j-1];

                     if (i>=1&&j>=1&&i<=k-1&&j<=k-1&&d[k-1][i][j]<minim)
                                        minim=d[k-1][i][j],pos=t[k-1][i][j];



                     d[k][i][j]=minim+v[k][i][j];
                     a[t[k][i][j]]=pos;
                     }
minim=1<<26;
for (i=1;i<=niv;i++) for (j=1;j<=niv;j++) {if (d[niv][i][j]<minim) {minim=d[niv][i][j];
                                                                    pos=t[niv][i][j];
                                                                    }

                                            }
fprintf(g,"%d\n",minim);
sol[niv]=pos;
for (i=niv-1;i>=1;i--) {sol[i]=a[pos];
                        pos=a[pos];}
for (i=1;i<=niv;i++) fprintf(g,"%d ",sol[i]);
return 0;
}
