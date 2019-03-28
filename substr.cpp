#include <cstdio>
#include <cstring>
#include <algorithm>
#define nmax 17000
#define teta 'z'-'0'+1
using namespace std;
int n,k,p,pmax,sol;
char s[nmax];
const int mod[5]={66015,66011,66013,10007,10013};
struct hashing{int h[5];} v[nmax],r;

int sorthashing(const hashing &a,const hashing &b)
{
    for (int i=0;i<4;i++)
        if (a.h[i]!=b.h[i])
            return a.h[i]<b.h[i];
    return 2;
}
int main()
{
    int i,j;
    freopen("substr.in","r",stdin);
    freopen("substr.out","w",stdout);
    scanf("%d %d\n%s\n",&n,&k,&s);
    int mijl,sol=0,st=0,dr=n;
    while (st<=dr) {
        mijl=(st+dr)>>1;
        memset(v,0,sizeof(v));

        for (j=0;j<5;j++)
            r.h[j]=1;
        for (i=1;i<mijl;i++)
            for (j=0;j<5;j++)
                r.h[j]=(1LL*r.h[j]*teta+mod[j])%mod[j];

        for (i=0;i<mijl;i++)
            for (j=0;j<5;j++) {
                v[mijl-1].h[j]*=teta;
                v[mijl-1].h[j]+=s[i]-'0';
                v[mijl-1].h[j]%=mod[j];
            }

        for (i=mijl;i<n;i++) {
            v[i]=v[i-1];
            for (j=0;j<5;j++) {
                v[i].h[j]-=((s[i-mijl]-'0')*r.h[j])%mod[j];
                v[i].h[j]+=mod[j];
                v[i].h[j]=(v[i].h[j]*teta+s[i]-'0')%mod[j];
            }
        }
        sort(v+mijl-1,v+n+1,sorthashing);
        p=pmax=1;
        for (i=mijl;i<n;i++) {
            if (sorthashing(v[i],v[i-1])==2)
                p++;
            else
                p=1;
            pmax=max(pmax,p);
        }
        if (pmax>=k) {
            sol=mijl;
            st=mijl+1;
        }
            dr=mijl-1;
    }
    printf("%d",sol);
    return 0;
}
