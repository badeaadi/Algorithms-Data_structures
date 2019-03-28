#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>
#define nmax 100005
#define mmax 1005
#define teta 2
using namespace std;
ifstream f("virus.in");
ofstream g("virus.out");
struct trie{
    int sol;
    trie *son[teta],*prev;
    vector <trie *> v;
    trie() {
        son[0]=son[1]=0;
        prev=0;
        sol=0;
    }
};
trie *root=new trie,*node,*aux,*r[mmax];
queue <trie *> q;
char s[nmax],a[mmax];
int n,m;

void dfs(trie *node)
{
    int i;
    for (i=0;i<node->v.size();i++) {
        dfs(node->v[i]);
        node->sol+=node->v[i]->sol;
    }
}
int main()
{
    int i,j,l;
    f>>n;f>>m;f.get();
    f.getline(s,nmax);

    for (i=1;i<=m;i++) {
        f>>j;f.get();
        memset(a,0,sizeof(a));
        f.getline(a,mmax);
        node=root;
        for (j=0;a[j];j++) {
            if (node->son[a[j]-'0']==0) {
                aux=new trie;
                node->son[a[j]-'0']=aux;
            }
            node=node->son[a[j]-'0'];
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
        while (node!=root&&node->son[s[i]-'0']==0)
            node=node->prev;
        if (node->son[s[i]-'0'])
            node=node->son[s[i]-'0'];
        node->sol++;
    }
    dfs(root);
    for (i=1;i<=m;i++)
        g<<r[i]->sol<<'\n';

    return 0;
}
