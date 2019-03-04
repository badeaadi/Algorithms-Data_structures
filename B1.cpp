#include <iostream>
#define nmax 200005
#define teta 90
using namespace std;
int n,st[nmax],dr[nmax],sol;
char a[nmax],b[nmax];

int v[teta][teta];
int k[teta][teta];

int main()
{
    int i,j,t;
    cin>>n;
    cin>>a+1>>b+1;
    for (i=1;i<=n;i++)
        if (a[i]!=b[i]) {
            v[a[i]-'A'][b[i]-'A']++;
            k[a[i]-'A'][b[i]-'A']=i;
            sol++;
        }
    for (i=0;i<teta;i++)
        for (j=0;j<teta;j++)
            if (v[i][j]&&v[j][i]) {
                cout<<sol-2<<'\n';
                cout<<k[i][j]<<' '<<k[j][i]<<'\n';
                return 0;
            }
    for (i=0;i<teta;i++) {
        for (j=0;j<teta;j++)
            for (t=0;t<teta;t++)
                if (v[j][i]&&v[i][t]) {
                    cout<<sol-1<<'\n';
                    cout<<k[j][i]<<' '<<k[i][t]<<'\n';
                    return 0;
                }
    }
    cout<<sol<<'\n';
    cout<<"-1 -1\n";
    return 0;
}
