#include <fstream>
#define nmax 500005
using namespace std;

int n,heap[nmax];

void heapdown(int fiu)
{
    int change = fiu;

    if (fiu *2 <= n && heap[fiu * 2]<heap[change])
        change= fiu* 2;
    if (fiu *2 + 1<=n && heap[fiu * 2 + 1]<heap[change])
        change= fiu* 2 + 1;

    if (fiu != change) {
        swap(heap[fiu], heap[change]);
        heapdown(change);
    }
}
void heapup(int fiu)
{
    if (fiu == 1)
        return;
    int tata=fiu / 2;
    if (heap[fiu] < heap[tata]) {
        swap(heap[fiu], heap[tata]);
        heapup(tata);
    }
}
int main()
{
    freopen("algsort.in","r",stdin);
    freopen("algsort.out","w",stdout);

    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&heap[i]);
        heapup(i);
    }
    while (n) {
        printf("%d ",heap[1]);
        heap[1]=heap[n];
        heap[n]=0;
        n--;
        heapdown(1);
    }
    return 0;
}