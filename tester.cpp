#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#define nmax 505
#define mmax 5005
using namespace std;
ifstream f("tester.in");
ofstream g("tester.out");
vector <int> k[mmax];
stack <int> s;
struct nod{int x;int y;int in;int ex;};
nod v[mmax];
int n,m,nrs=-1;
int sol[nmax*mmax],nrsol,nr;
char st[mmax*nmax*3];

void creeaza(int i,int j)
{
    k[j].push_back(i);
    v[j].ex++;
    v[i].in++;
}
void fleury(int nod)
{
    int nod2;
    s.push(nod);
    while (!s.empty()) {
        nod=s.top();
        if (v[nod].ex==0) {
            sol[++nrsol]=nod;
            s.pop();
            continue;
        }
        nod2=k[nod][k[nod].size()-1];
        k[nod].erase(k[nod].end()-1);
        v[nod].ex--;
        v[nod2].in--;
        s.push(nod2);
    }

}
void add(int x)
{
    int nrs1=nrs;
    while (x) {
        st[++nrs]=x%10+'0';
        x/=10;
    }
    reverse(st+nrs1+1,st+nrs+1);

}
int main()
{
    int i,j,t;
    f>>n>>m;
    for (i=1;i<=m;i++)
        f>>v[i].x>>v[i].y;

    for (i=1;i<=m;i++)
        for (j=1;j<=m;j++)
            if (i!=j&&v[i].y==v[j].x)
                    creeaza(i,j);
    for (i=1;i<=m;i++) {
        while (v[i].ex<v[i].in)
            creeaza(0,i);
        while (v[i].in<v[i].ex)
            creeaza(i,0);
    }
    for (i=0;i<=m;i++) {
        if (v[i].ex!=0)
            fleury(i);
    }
    j=1;
    for (i=1;i<=nrsol+1;i++) {
        if (sol[i]==0) {
            if (i-j+1>=2) {
                if (nr) {
                    st[++nrs]='R';
                    st[++nrs]=' ';
                }
                nr++;;
                add(v[sol[j]].x);
                st[++nrs]=' ';
                for (t=j;t<i;t++) {
                    add(v[sol[t]].y);
                    st[++nrs]=' ';
                }
            }
            j=i+1;
        }
    }
    g<<st<<'\n';
    return 0;
}
