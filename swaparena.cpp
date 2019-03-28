#include <fstream>
#include <cstring>
#define ub(i) i&(-i)
#define nmax 50050
#define teta 26
using namespace std;
ifstream f("swap.in");
ofstream g("swap.out");
int sa[teta],sb[teta];
int x[teta],lit,n,m;
char s[nmax],t[nmax],r[nmax];
int v[nmax],aib[nmax];
long long sol;

int query(int poz)
{
    int sum=0;
    for (;poz>=1;poz-=ub(poz))
        sum+=aib[poz];
    return sum;
}
void update(int poz,int val)
{
    for (;poz<=n+2;poz+=ub(poz))
        aib[poz]+=val;
}

int main()
{
    int i,j;
    f.getline(s,nmax);
    f.getline(t,nmax);

    memcpy(r,s,sizeof(r));
    memset(s,0,sizeof(s));
    memcpy(s,t,sizeof(r));
    memset(t,0,sizeof(s));
    memcpy(t,r,sizeof(r));

    n=strlen(s);
    m=strlen(t);
    if (n!=m) {
        g<<-1<<'\n';
        return 0;
    }


    for (i=n-1;i>=0;i--)
        sa[s[i]-'a']++;
    for (i=m-1;i>=0;i--)
        sb[t[i]-'a']++;
    for (i=0;i<teta;i++)
        if (sa[i]!=sb[i]) {
            g<<-1<<'\n';
            return 0;
        }
    for (i=0;t[i];i++) {
        lit=t[i]-'a';
        while (s[x[lit]]!=t[i])
                x[lit]++;
        v[i+1]=x[lit]+1;
        x[lit]++;
    }
    sol=1LL*n*(n-1)/2;
    for (i=1;i<=n;i++) {
        sol-=query(v[i]-1);
        update(v[i],1);
    }
    g<<sol;
    return 0;
}
