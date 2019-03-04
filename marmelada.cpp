#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
using namespace std;
#define NMAX 100005
ifstream fin("marmelada.in");
ofstream fout("marmelada.out");

typedef pair<int,int> iPair;

int n, m, s, d, minLevel = NMAX;
int sol[NMAX];
int distances[NMAX], visited[NMAX];

vector<pair <int, int> > v[NMAX];
vector<int> drumMin;
int Prev[NMAX],getto[NMAX];
priority_queue<iPair, vector<iPair> , greater<> > pq;

queue<int> nodes;

void ReadInput()
{
    fin >> n >> m >> s >> d;
    int x,y,i;
    for(i = 1; i <= m ; ++i) {
        fin >> x >> y;
        v[x].push_back(make_pair(y, i));
        v[y].push_back(make_pair(x, i));
    }
    for(i = 1;i <=m ; ++i)
    {
        fin >> x;
        pq.push({x,i});
    }
}
void Solve(int x)
{
    nodes.push(x);

    visited[x] = true;
    while(!nodes.empty())
    {
        int node = nodes.front();
        nodes.pop();

        for(auto child : v[node])
        {
            if(!visited[child.first]){
                distances[child.first] = distances[node]+1;
                getto[child.first] = child.second;
                Prev[child.first] = node;
                visited[child.first] = true;
                nodes.push(child.first);
                if(child.first == d)
                {
                    return;
                }
            }
        }
    }
}
int main()
{
    minLevel = 10005;
    ReadInput();
    Solve(s);
    int dd = d;
    while(Prev[dd])
    {
        drumMin.push_back(dd);
        dd = Prev[dd];
    }
    drumMin.push_back(s);
    for(int i = drumMin.size()-1; i> 0; --i)
    {
        sol[getto[drumMin[i-1]]] = pq.top().second;
        pq.pop();
    }


    for(int i = 1; i <= m; ++i)
    {
        if(sol[i])
            fout << sol[i] << endl;
        else
        {
            fout << pq.top().second << endl;
            pq.pop();
        }
    }

}
