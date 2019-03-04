#include <fstream>
#include <ctime>
#include <cstdlib>
#define nmax 500005
using namespace std;
ifstream f("algsort.in");
ofstream g("algsort.out");
int n,v[nmax];

struct treap{
    int val,pri;
    treap *st,*dr;
    treap(int value,int prior,treap *x,treap *y) {
        this->val=value;
        this->pri=prior;
        this->st=x;
        this->dr=y;
    }
};
treap *nil,*r;

void rotateright(treap * &r)
{
    treap *aux=r->st;
    r->st=aux->dr;
    aux->dr=r;
    r=aux;
}
void rotateleft(treap *&r)
{
    treap *aux=r->dr;
    r->dr=aux->st;
    aux->st=r;
    r=aux;
}
void insertnode(treap * &r,int value,int prior)
{
    if (r==nil) {
        r=new treap(value,prior,nil,nil);
        return;
    }
    if (value<r->val)
        insertnode(r->st,value,prior);
    else
        insertnode(r->dr,value,prior);

    if (r->st!=NULL&&r->pri < r->st->pri)
        rotateright(r);
    else
        if (r->dr!=NULL&&r->pri < r->dr->pri)
            rotateleft(r);
}
void removenode(treap * &r,int value)
{
    if (r==nil)
        return;

    if (r->val>value||r->st->val==value)
        removenode(r->st,value);
    else
        if (r->val<value||r->dr->val==value)
            removenode(r->dr,value);
        else
            if (r->st==nil&&r->dr==nil) {
                delete r;
                r=nil;
            }
            else {
                if (r->st->pri > r->dr->pri)
                    rotateright(r);
                else
                    rotateleft(r);
                removenode(r,value);
            }
}
void writesol(treap * &r)
{
    if (r->st!=nil)
        writesol(r->st);
    g<<r->val<<' ';
    if (r->dr!=nil)
        writesol(r->dr);
}
int main()
{
    int i,j;
    f>>n;
    r=nil=new treap(0,rand(),nil,nil);
    srand(time(0));
    for (i=1;i<=n;i++) {
        f>>v[i];
        insertnode(r,v[i],rand());
    }
    writesol(r);

    for (i=1;i<=n;i++)
        removenode(r,v[i]);

    if (r!=nil)
        writesol(r);

    return 0;
}
