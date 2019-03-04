#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    priority_queue <int> max_queue;
    priority_queue <int, vector<int>, greater<int> > min_queue;
    //freopen("date.in","r",stdin);

    scanf("%d %d",&n,&m);
    for (int i=1; i<= m; i++) {
        int j;
        scanf("%d", &j);
        max_queue.push(j);
        min_queue.push(j);
    }
    int solmin=0,solmax=0;
    for (int i=1; i<=n ; i++) {
        int k= min_queue.top();
        min_queue.pop();
        solmin+=k;
        if (k>1)
            min_queue.push(k-1);


        k=max_queue.top();
        max_queue.pop();
        solmax+=k;
        if (k>1)
            max_queue.push(k-1);
    }
    printf("%d %d",solmax,solmin);
    return 0;
}