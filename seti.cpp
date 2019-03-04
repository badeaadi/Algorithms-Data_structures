#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#define nmax 150000
#define teta 60
#define mmax 25
using namespace std;
ifstream f("seti.in");
ofstream g("seti.out");
struct trie{
    int sol;
    trie *son[teta],*prev;
    vector <trie *> v;
    trie() {
        memset(son,0,sizeof(son));
        prev=0;
        sol=0;
    }
};
trie *root=new trie,*node,*aux,*r[nmax/2];
queue <trie *> q;
char s[nmax],a[mmax];
int n,m;

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
    int i,j,l;
    f>>n;f.get();
    for (i=1;i<=n;i++)
        f.getline(s+(i-1)*64,nmax);
    f>>m;f.get();
    for (i=1;i<=m;i++) {
        memset(a,0,sizeof(a));
        f.getline(a,25);
        node=root;
        for (j=0;a[j];j++) {
            if (node->son[a[j]-'A']==0) {
                aux=new trie;
                node->son[a[j]-'A']=aux;
            }
            node=node->son[a[j]-'A'];
        }
        r[i]=node;
    }
    q.push(root);
    while (!q.empty()) {
        node=q.front();
        q.pop();
        for (i=0;i<teta;i++)
            if (node->son[i]) {
                aux=node->prev;
                while (aux&&aux->son[i]==0)
                    aux=aux->prev;
                if (!aux)
                    node->son[i]->prev=root;
                else
                    node->son[i]->prev=aux->son[i];
            node->son[i]->prev->v.push_back(node->son[i]);
            q.push(node->son[i]);
        }
    }
    node=root;
    for (i=0;s[i];i++)  {
        while (node!=root&&node->son[s[i]-'A']==0)
            node=node->prev;
        if (node->son[s[i]-'A'])
            node=node->son[s[i]-'A'];
        node->sol++;
    }
    dfs(root);
    for (i=1;i<=m;i++)
        g<<r[i]->sol<<'\n';

    return 0;
}
