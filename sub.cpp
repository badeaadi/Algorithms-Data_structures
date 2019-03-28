#include <fstream>
#include <cstring>
#define nmax 305
using namespace std;
ifstream f("sub.in");
ofstream g("sub.out");
int n,sum,ans;
char s[nmax];

struct trie{
    int inf,inf2;
    trie *fiu[26];
    trie() {
        inf=0;inf2=0;
        memset(fiu,0,sizeof(fiu));
    }
};
trie *t=new trie;

void dfs(trie *nod)
{
    if (nod->inf==sum)
        ans++;

    for (int i=0;i<26;i++)
        if (nod->fiu[i]!=NULL)
            dfs(nod->fiu[i]);
}


int main()
{
    int i,j,k;
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,nmax);
        for (j=0;s[j];j++) {
            trie *nod=t;
            for (k=j;s[k];k++) {
                if (nod->fiu[s[k]-'a']==NULL) {
                    if (i==1) {
                        trie *aux=new trie;
                        nod->fiu[s[k]-'a']=aux;
                    }
                }

                if (nod->fiu[s[k]-'a']!=NULL) {
                    nod=nod->fiu[s[k]-'a'];
                    nod->inf2=i;
                }
                else
                    break;
            }
        }
        for (j=0;s[j];j++) {
            trie *nod=t;
            for (k=j;s[k];k++) {
                if (nod->fiu[s[k]-'a']==NULL)
                    break;

                nod=nod->fiu[s[k]-'a'];
                nod->inf+=nod->inf2;
                nod->inf2=0;
            }
        }
    }
    sum=n*(n+1)/2;
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(s,0,sizeof(s));
        f.getline(s,nmax);
        for (j=0;s[j];j++) {
            trie *nod=t;
            for (k=j;s[k];k++) {
                if (nod->fiu[s[k]-'a']==NULL)
                    break;
                nod=nod->fiu[s[k]-'a'];
                nod->inf=0;
            }
        }
    }
    memset(s,0,sizeof(s));
    dfs(t);
    g<<ans<<'\n';
    return 0;
}
