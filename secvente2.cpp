#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#define nmax 200005
using namespace std;
ifstream f("secvente2.in");
FILE *g=fopen("secvente2.out","w");
struct element {int a;int b;};
element v[nmax];
int n,t[nmax],x[nmax][2],jmax,jmin,maxim,na;
char a[10],s[10];


bool compare(const element &a,const element &b)
{
    return a.a<b.a;
}
int tata(int x)
{
    while (t[x]>=0)
        x=t[x];
    return x;
}
void write(int x)
{
    int i=0;
    while (x) {
        a[i++]=x%10+'0';
        x/=10;
    }
    reverse(a,a+i);
    fprintf(g,"%s\n",a);
}
void dotie(int p,int q)
{
    int t1,t2;
    t1=tata(p);
    t2=tata(q);
    if (-t[t1]>-t[t2]){
        t[t1]+=t[t2];
        maxim=max(maxim,-t[t1]);
        t[t2]=t1;
    }
    else {
        t[t2]+=t[t1];
        maxim=max(maxim,-t[t2]);
        t[t1]=t2;
    }
}
int main()
{
    int i,j,k,t1,t2;
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,10);
        j=0;
        while (s[j])
            v[i].a=v[i].a*10+s[j++]-'0';
        v[i].b=i;
    }
    sort(v+1,v+n+1,compare);
    for (i=1;i<n;i++) {
        if (v[i+1].a-v[i].a==1) {
            jmax=max(v[i+1].b,v[i].b);
            jmin=min(v[i+1].b,v[i].b);
            if (x[jmax][0]==0)
                x[jmax][0]=jmin;
            else
                x[jmax][1]=jmin;
        }
    }
    maxim=1;
    for (j=1;j<=n;j++) {
        t[j]=-1;
        if (x[j][0])
            dotie(j,x[j][0]);
        if (x[j][1])
            dotie(j,x[j][1]);
        write(maxim);
    }
    return 0;
}
