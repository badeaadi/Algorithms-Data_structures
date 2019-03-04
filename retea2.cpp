#include <iomanip>
#include <fstream>
#include <cmath>
#define per pair<double,double>
#define nmax 2005
#define inf 1<<30
using namespace std;
per a[nmax],b[nmax];
double t[nmax],sol;
int heap[nmax],nrh,poz[nmax];
int n,m;

inline double dist(per p,per q)
{
    double l=p.first-q.first;
    double c=p.second-q.second;
    return sqrt(l*l+c*c);
}
void add(int nod)
{
    heap[++nrh]=nod;
    poz[nod]=nrh;
}
void upheap(int nod)
{
    while (nod>1&&t[heap[nod]]<t[heap[nod/2]]) {
        swap(poz[heap[nod]],poz[heap[nod/2]]);
        swap(heap[nod],heap[nod/2]);
        nod/=2;
    }
}
void downheap(int nod)
{
    int fiu1,fiu2,nod2;
    do
    {
        nod2=nod;

        fiu1=nod*2;
        if (fiu1<=nrh&&t[heap[fiu1]]<t[heap[nod2]])
            nod2=fiu1;

        fiu2=nod*2+1;
        if (fiu2<=nrh&&t[heap[fiu2]]<t[heap[nod2]])
            nod2=fiu2;

        if (nod!=nod2) {
            swap(poz[heap[nod]],poz[heap[nod2]]);
            swap(heap[nod],heap[nod2]);
            nod=nod2;
        }
        else
            break;

    } while (1);
}
void popheap(int nod)
{
    poz[heap[nod]]=0;
    heap[nod]=heap[nrh];
    heap[nrh]=0;
    nrh--;
    poz[heap[nod]]=nod;
    downheap(nod);
}
int main()
{
    int i,j;
    double d;
    ifstream f("retea2.in");
    ofstream g("retea2.out");
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i].first>>a[i].second;
    for (i=1;i<=m;i++) {
        f>>b[i].first>>b[i].second;
        t[i]=inf;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) {
            d=dist(a[i],b[j]);
            if (d<t[j])
                t[j]=d;
    }
    for (j=1;j<=m;j++) {
        add(j);
        upheap(poz[j]);
    }

    int nod;
    for (i=1;i<=m;i++) {
        nod=heap[1];
        sol+=t[nod];
        t[nod]=0;
        popheap(1);
        downheap(1);
        for (j=1;j<=m;j++)
            if (t[j]!=0) {
                d=dist(b[nod],b[j]);
                if (d<t[j]) {
                    t[j]=d;
                    upheap(poz[j]);
                }
            }
    }
    g<<setprecision(6)<<fixed<<sol;

    return 0;
}
