#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define nmax 1000005
#define fmax 755
#define teta 26
using namespace std;
char s[nmax];
vector <int> sol[teta][teta];
vector <int> v[fmax];
bitset <fmax> b;
queue <int> q;
int n,m,c[fmax][fmax],f[fmax][fmax];
int t[fmax],p[teta],k[teta][teta],dest;

 int aux[nmax];

int bfs()
{
    int i,j,l;
    while (!q.empty())
        q.pop();
    q.push(0);
    b.reset();
    b[0]=1;
    while (!q.empty()) {
        l=q.front();
        q.pop();
        for (i=0;i<v[l].size();i++) {
            j=v[l][i];
            if (b[j]==0&&f[l][j]<c[l][j]) {
                b[j]=1;
                t[j]=l;
                if (j==dest)
                    return 1;
                q.push(j);
            }
        }
    }
    return 0;
}
int main()
{
    int i,j,l,r;
    char a,b;
    freopen("teroristi.in","r",stdin);
    freopen("teroristi.out","w",stdout);
    scanf("%d %d\n%s\n",&n,&m,&s);
    for (i=0;i<n;i++)
        p[s[i]-'a']++;
    for (i=1;i<=m;i++) {
        scanf("%c %c\n",&a,&b);
        k[a-'a'][b-'a']++;
        sol[a-'a'][b-'a'].push_back(i);
    }
    for (i=0;i<teta;i++)
        for (j=0;j<teta;j++) {
            l=i*teta+j+1;
            c[0][l]=k[i][j];
            v[0].push_back(l);
            v[l].push_back(0);
        }
    dest=fmax-1;
    l=teta*teta+1;
    for (r=0;r<teta;r++,l++) {
        if (p[r]==0)
            continue;
        c[l][dest]=p[r];
        v[l].push_back(dest);
        v[dest].push_back(r);
        for (i=0;i<teta;i++)
            for (j=0;j<teta;j++)
                if (k[i][j]&&(i==r||j==r)) {
                    c[i*teta+j+1][l]=1<<20;
                    v[i*teta+j+1].push_back(l);
                    v[l].push_back(i*teta+j+1);
                }
    }
    int flow;i=0;
    while (bfs()) {
        flow=1<<30;
        for (i=dest;i;i=t[i])
            flow=min(flow,c[t[i]][i]-f[t[i]][i]);
        for (i=dest;i;i=t[i]) {
            f[t[i]][i]+=flow;
            f[i][t[i]]-=flow;
        }
    }

    for (i=0;i<n;i++) {
        l=teta*teta+1+s[i]-'a';
        for (j=0;j<teta;j++) {
            r=s[i]-'a';
            a=r;b=j;
            if (f[a*teta+b+1][l]==0&&f[b*teta+a+1][l]==0)
                continue;
            if (f[b*teta+a+1][l])
                swap(a,b);

            f[a*teta+b+1][l]--;
            printf("%d ",sol[a][b][sol[a][b].size()-1]);
            sol[a][b].erase(sol[a][b].begin()+sol[a][b].size()-1);
            break;
        }
    }

    return 0;
}
