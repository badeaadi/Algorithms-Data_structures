#include <fstream>
#include <cstring>
#include <queue>
#include <vector>
#define nmax 105
#define lmax1 1000005
#define lmax2 10005
#define teta 26
using namespace std;
ifstream f("ahocorasick.in");
ofstream g("ahocorasick.out");
struct trie{
    int sol;
    trie *fiu[teta],*prev;
    vector<trie *> v;
    trie() {
        memset(fiu,0,sizeof(fiu));
        prev=0;
        sol=0;
    }
};
int n;
char s[lmax1];
char t[lmax2];
trie *q[nmax];
trie *root=new trie;
trie *nod,*aux;
queue <trie *> r;


void dfs(trie *nod)
{
    int i;
    for (i=0;i<nod->v.size();i++) {
        dfs(nod->v[i]);
        nod->sol+=nod->v[i]->sol;
    }
}

int main()
{
    int i,j;
    f.getline(s,lmax1);
    f>>n;f.get();
    for (i=1;i<=n;i++) {
        memset(t,0,sizeof(t));
        f.getline(t,lmax2);
        nod=root;
        for (j=0;t[j];j++) {
            if (!nod->fiu[t[j]-'a']) {
                trie *aux=new trie;
                nod->fiu[t[j]-'a']=aux;
                nod=nod->fiu[t[j]-'a'];
            }
            else {
                nod=nod->fiu[t[j]-'a'];

            }
        }
        q[i]=nod;
    }
    r.push(root);
    while (!r.empty()) {
        nod=r.front();
        r.pop();
        for (i=0;i<teta;i++)
            if (nod->fiu[i]) {
                aux=nod->prev;
                while (aux&&aux->fiu[i]==0)
                    aux=aux->prev;
                if (!aux) {
                    nod->fiu[i]->prev=root;
                }
                else {
                    nod->fiu[i]->prev=aux->fiu[i];
                }
                nod->fiu[i]->prev->v.push_back(nod->fiu[i]);
                r.push(nod->fiu[i]);
            }
    }
    aux=root;
    for (i=0;s[i];i++)  {
        while (aux!=root&&aux->fiu[s[i]-'a']==0)
            aux=aux->prev;
        if (aux->fiu[s[i]-'a'])
            aux=aux->fiu[s[i]-'a'];
        aux->sol++;
    }
    dfs(root);
    for (i=1;i<=n;i++)
        g<<q[i]->sol<<'\n';

    return 0;
}
