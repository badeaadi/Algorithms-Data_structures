#include <cstdio>
#include <cstring>
#include <fstream>
#include <cmath>
#define maxn 1000
using namespace std;
long double x[maxn],y[maxn];
int n;
ifstream f("tri2.in");
ofstream g("tri2.out");
void solve();

int main()
{
    int i;
    f>>n;
    for (i=0;i<n;i++)
        f>>x[i]>>y[i];
    solve();
    return 0;
}
void solve()
{
    int i,j,k,m,p,q,smn,cnt,ok;
    long double a[3],b[3],c[3],sm[3],xt[4],yt[4],xx,yy,r,eps=1e-6;
    f>>m;
    for (p=1;p<=m;p++) {
        f>>i>>j>>k;
        i--;j--;k--;
        xx=(x[i]+x[j]+x[k])/3.0;
        yy=(y[i]+y[j]+y[k])/3.0 ;

        xt[0]=xt[3]=x[i];yt[0]=yt[3]=y[i];
        xt[1]=x[j]; yt[1]=y[j];
        xt[2]=x[k]; yt[2]=y[k];

        for (q=0;q<3;q++) {
            a[q]=yt[q]-yt[q+1];
            b[q]=xt[q+1]-xt[q];
            c[q]=xt[q]*yt[q+1]-xt[q+1]*yt[q];
            r=a[q]*xx+b[q]*yy+c[q];

        if (r>0)
            sm[q]=1;
        else
            sm[q]=-1;
        }
    for (cnt=i=0;i<n;i++){
        for (ok=1,q=0;q<3;q++) {
            r=a[q]*x[i]+b[q]*y[i]+c[q];
        if (fabs(r)<eps) smn=0;
        else
            if (r>0) smn=1;
        else
            smn=-1;
        if (smn!=sm[q]){
            ok=0;
            break;
        }
      }
    if (ok)
      cnt++;
    }
    g<<cnt<<'\n';
  }
}
