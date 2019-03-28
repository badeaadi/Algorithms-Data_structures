#include <fstream>
#include <algorithm>
#include <cstdio>
FILE *f=fopen("simetric1.in","r");
FILE *g=fopen("simetric1.out","w");
using namespace std;
#define nmax 405

int n,m,a[nmax][nmax],best[nmax][nmax];
int sol,cnt[nmax];

int main()
{
	int i,j,k;
	fscanf(f,"%d %d",&n,&m);
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			fscanf(f,"%d",&a[i][j]);

	for (i=n;i>=1;i--)
		for (j=m;j>=1;j--)
		{
			for (k=1;i+k<=n&&j+k<=m&&a[i+k][j]==a[i][j+k];k++);

			best[i][j]=min(best[i+1][j+1]+1, k);
            sol=max(sol,best[i][j]);
			cnt[best[i][j]]++;
		}

	for (i=sol-1;i>=1;i--)
		cnt[i]+=cnt[i+1];
	for (i=1;i<=sol;i++)
        fprintf(g,"%d\n",cnt[i]);

	return 0;
}
