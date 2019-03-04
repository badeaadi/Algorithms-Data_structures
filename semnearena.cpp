#include <bits/stdc++.h>
#define nmax 50005
using namespace std;
int n,poz,v[nmax];
long long s,sum;
char sol[nmax];
vector <int> p,m;
int main()
{
    int i,j;
    freopen("semne.in","r",stdin);
    freopen("semne.out","w",stdout);
    scanf("%d %lld",&n,&s);
    srand(time(0));
    for (i=0;i<n;i++) {
        scanf("%d",&v[i]);
        if (sum>s) {
            sum-=v[i];
            m.push_back(i);
        }
        else {
            sum+=v[i];
            p.push_back(i);
        }
    }
    while (sum!=s) {
        poz=rand();
        if (sum<s) {
            poz%=m.size();
            p.push_back(m[poz]);
            sum+=2*v[m[poz]];
            swap(m[poz],m[m.size()-1]);
            m.pop_back();
        }
        else {
            poz%=p.size();
            m.push_back(p[poz]);
            sum-=2*v[p[poz]];
            swap(p[poz],p[p.size()-1]);
            p.pop_back();
        }
    }
    for (i=0;i<m.size();i++)
        sol[m[i]]='-';
    for (i=0;i<p.size();i++)
        sol[p[i]]='+';
    printf("%s\n",sol);
    return 0;
}
