#include <fstream>
#include <set>
#include <algorithm>
#define nmax 1005
using namespace std;

int n,s,v[nmax],sol;
int st[nmax*nmax/2],dr[nmax*nmax/2];
int na,nb;

ifstream f("take5.in");
ofstream g("take5.out");


void er(int pos)
{
    int i,step=0, now=pos+1;
    for (i=1;i<=nb;i++) {
        while (dr[i+step]==v[pos]+v[now]&&now<=n) {
            now++;
            step++;
            nb--;
        }
        dr[i]=dr[i+step];
    }

}
void ins(int pos)
{
    int i,x=na,y=pos-1;
    st[0]=-1;
    for (i=na+pos-1;i>=1;i--) {

        if (y>0&&v[pos]+v[y]>st[x]) {

            st[i]=v[pos]+v[y--];
            if (y==0)
                break;
        }
        else
            st[i]=st[x--];
    }
    na+=pos-1;
}

void solve()
{
    int i,j,k,tofind,o;
    int x,y;

    for (i=3;i<=n;i++)
        for (j=i+1;j<=n;j++)
            dr[++nb]=v[i]+v[j];
    sort(dr+1,dr+nb+1);

    for (i=3;i<=n-2;i++) {
        ins(i-1);
        er(i);
        tofind=s-v[i];
        if (tofind<0)
            break;

        j=1;
        k=nb;
        while (j<=na&&k>=1) {
            o=st[j]+dr[k];
            if (o==tofind) {
                x=y=0;

                while (j<=na&&st[j]==st[j+1])
                    x++,j++;
                while (k>=1&&dr[k]==dr[k-1])
                    y++,k--;
                sol+=(x+1)*(y+1);
                j++;
                k--;
            }
            else
                if (o<tofind)
                    j++;
                else
                    k--;

        }
    }
    g<<sol<<'\n';

}
int main()
{

    int i,j;
    f>>n>>s;
    for (i=1;i<=n;i++)
        f>>v[i];
    sort(v+1,v+n+1);

    solve();

    return 0;
}
