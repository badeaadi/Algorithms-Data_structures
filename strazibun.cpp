#include <fstream>
#include <vector>
#include <bitset>

#define DIM 256

using namespace std;

ifstream fin("strazi.in");
ofstream fout("strazi.out");

bool X[DIM][DIM];

vector<int> L[DIM];

bool v[DIM];

int drum[DIM], stanga[DIM], dreapta[DIM];

int n, m, a, b, k, ok, nr;

bool cuplaj(int nod)
{
    v[nod] = true;

    for(int i = 0; i < L[nod].size(); i ++)
    {
        int a = L[nod][i];
        if(dreapta[a] == 0)
        {
            stanga[nod] = a;
            dreapta[a] = nod;
            return true;
        }
    }
    for(int i = 0; i < L[nod].size(); i ++)
    {
        int a = L[nod][i];
        if(v[dreapta[a]] == false && cuplaj(dreapta[a]) )
        {
            stanga[nod] = a;
            dreapta[a] = nod;
            return true;
        }
    }

    return false;
}

void dfs(int nod){

    drum[++k] = nod;

    if(stanga[nod])
        dfs(stanga[nod]);

}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= m; i ++)
    {
        fin >> a >> b;
        L[a].push_back(b);
        X[a][b] = true;
    }

    while(1)
    {
        ok = 0;
        for(int i = 1; i <= n; i ++)
        {
            v[i] = false;
        }
        for(int i = 1; i <= n; i ++)
        {
            if( stanga[i] == 0 && cuplaj(i) == true )
            {
                nr ++;
                ok = 1;
            }
        }

        if(ok == 0)
            break;
    }

    fout << n - 1 - nr << '\n';

    for(int i = 1; i <= n; i ++)
    {
        if(dreapta[i] == 0)
        {
            dfs(i);
        }
    }

    for(int i = 1; i < k; i ++)
    {
        if(X[drum[i]][drum[i + 1]] == false)
        {
            fout << drum[i] << " " << drum[i + 1] << '\n';
        }
    }

    for(int i = 1; i <= k; i ++)
    {
        fout << drum[i] << " ";
    }

    return 0;
}
