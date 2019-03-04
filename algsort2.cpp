#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quickSort(int v[], int left, int right) {

    int a = rand() % (right - left + 1) + left;
    int b = rand() % (right - left + 1) + left;
    int c = rand() % (right - left + 1) + left;

    int pivot = v[a] + v[b] + v[c] - min(a,min(b, c)) - max(a, max(b,c));

    int i = left, j = right;

    while (i <= j) {
        while (v[i] < pivot && i < right) {
            i++;
        }
        while (v[j] > pivot and j > left) {
            j--;
        }
        if (i <= j) {
            swap(v[i], v[j]);
            i++, j--;
        }
    }
    if (j >= left) {
        quickSort(v, left, j);
    }
    if (i <= right) {
        quickSort(v, i, right);
    }
}

int main() {

    freopen("algsort.in", "r", stdin);
    freopen("algsort.out", "w", stdout);
    int v[500000], n, i;
    srand(time(0));
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> v[i];

    quickSort(v, 0, n - 1);

    for (i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}