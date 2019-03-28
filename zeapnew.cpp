#include <fstream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#define nmax 300005
#define inf 1<<30
using namespace std;
ifstream f("zeap.in");
ofstream g("zeap.out");
int n,m;
char s[20];
set <int> p;
set <int> ::iterator itx,ity;
multiset <int> dif;

void solve()
{
    if (strcmp(s,"MIN")==0){
        if (p.size()<2)
            g<<-1<<'\n';
        else
            g<<*dif.begin()<<'\n';
        return;
    }
    if (strcmp(s,"MAX")==0){
        if (p.size()<2)
            g<<-1<<'\n';
        else {
            itx=p.end();itx--;
            g<<*itx-*p.begin()<<'\n';
        }
        return;
    }
    int x=0,y;
    for (int i=2;i<m;i++)
        x=x*10+s[i]-'0';

    if (s[0]=='C') {
        g<<p.count(x)<<'\n';
        return;
    }
    if (s[0]=='I') {
        if (p.count(x)!=0)
            return;

        p.insert(x);
        itx=p.find(x);ity=itx;
        ity++;
        if (itx!=p.begin()&&ity!=p.end()) {
            itx--;
            dif.erase(dif.find(*ity-*itx));
            itx++;
        }
        if (ity!=p.end())
            dif.insert(*ity-x);
        if (itx!=p.begin()) {
            itx--;
            dif.insert(x-*itx);
        }
        return;
    }
    if (p.count(x)==0) {
        g<<-1<<'\n';
        return;
    }
    itx=p.find(x);ity=itx;
    ity++;
    if (itx!=p.begin()&&ity!=p.end()) {
        itx--;
        dif.insert(*ity-*itx);
        itx++;
    }
    if (ity!=p.end())
        dif.erase(dif.find(*ity-x));
    if (itx!=p.begin()) {
        itx--;
        dif.erase(dif.find(x-*itx));
    }
    p.erase(x);
}
int main()
{
    int i,j;
    while (1) {
        f.getline(s,20);
        m=strlen(s);
        if (m==0)
            break;
        solve();
    }
    return 0;
}
