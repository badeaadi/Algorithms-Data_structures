#include <fstream>
using namespace std;
ifstream f("algsort.in");
ofstream g("algsort.out");
int n;

struct nod {
    int inf;
    nod *st,*dr;
};
nod *r;

void inserare(nod *&r, int x)
{
    if(r == NULL) {
        r = new nod;
        r->inf = x;
        r->st = r->dr = NULL;
    } else
        if (x < r->inf)
            inserare(r->st, x);
        else
            inserare(r->dr, x);
}
void parcurgere(nod *r, int niv) {

    if (r != NULL) {
        parcurgere( r->dr, niv+1 );

        for (int i = 1; i<= niv; i++)
            g<<"   ";

        g<< r->inf<<'\n';
        parcurgere( r->st, niv+1 );
    }

}

int main()
{
    int i,x;
    f>>n;
    for (i=1;i<=n;i++) {
        f>>x;
        inserare(r,x);
    }
    parcurgere(r, 1);

    return 0;
}
