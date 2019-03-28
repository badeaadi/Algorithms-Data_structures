#include <iostream>
#define nmax 1000005
#define logmax 35
using namespace std;
int n,sol,v[nmax];

struct trie{
    trie *son[2];int val;
    trie() {
        val=0;
        son[0]=0;
        son[1]=0;
        }
    } *t=new trie,*p;


void solvebrute()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=i;j<=n;j++)
            p^=(v[i]+v[j]);
    cout<<p<<'\n';
}
void addtrie(int k,trie *t)
{
    int i,j;
    for (i=0;i<=30;i++) {
        j=((k&(1<<i))!=0);
        if (t->son[j]==0) {
            p=new trie;
            t->son[j]=p;
        }
        t=t->son[j];
    }
    t->val++;
}
void vertrie(int k,int *t,int a)
{
    if (a>=29) {
        q
    }

    vertrie(k,t,a+1);

}
int main()
{
    int i,j;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[i];
    if (n<=5000)
        solvebrute();
    cout<<p<<'\n';

    for (i=1;i<=n;i++) {
        addtrie(v[i],t);
        vertrie(v[i],t,0);
    }
    return 0;
}
