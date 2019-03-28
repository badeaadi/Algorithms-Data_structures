#include<fstream>

using namespace std;

ifstream fin( "xormax.in" ); ofstream fout( "xormax.out" );

const int nmax = 1e5;
const int inf = nmax + 1;
int s[ nmax + 1 ];

struct Trie{
    Trie *f[ 2 ];
    int ind;

    Trie() {
        ind = -1;
        f[ 0 ] = f[ 1 ] = NULL;
    }
};

Trie *root;

void adauga( Trie *nod, int nmb, int ind, int pos = 21 ) {
    if ( pos == -1 ) {
        nod -> ind = ind;
        return ;
    }
    int val = (nmb >> pos) & 1;
    if ( nod -> f[ val ] == NULL ) {
        nod -> f[ val ] = new Trie();
    }
    adauga( nod -> f[ val ], nmb, ind, pos - 1 );
}
int cauta( Trie *nod, int nmb, int pos = 21 ) {
    if ( pos == -1 ) {
        return nod -> ind;
    }
    int val = (nmb >> pos) & 1;
    if ( nod -> f[ 1 - val ] != NULL ) {
        val = 1 - val;
    }
    return cauta( nod -> f[ val ], nmb, pos - 1 );
}
int main() {
    int n;
    fin >> n;
    root = new Trie();

    adauga( root, 0, 0 );

    int ans, a, b;
    ans = -inf, a = -inf, b = inf;
    for( int i = 1; i <= n; ++ i ) {
        int x;
        fin >> x;
        s[ i ] = s[ i - 1 ] ^ x;
        int pos = cauta( root, s[ i ] );
        if ( ans < ( s[ i ] ^ s[ pos ] ) ) {
            ans = ( s[ i ] ^ s[ pos ] );
            a = pos + 1;
            b = i;
        }
        adauga( root, s[ i ], i );
    }
    fout << ans << " " << a << " " << b << "\n";
    fin.close();
    fout.close();
    return 0;
}
