#include <iostream>

using namespace std;

int arr[101] = { 0, };

int main() {
    int n, m;
    cin >> n >> m;

    int size=n;

    while(m-->0) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int idx=i-1; idx<j; idx++) {
            arr[idx] = k;
        }
    }

    for (int it=0; it<size; it++) cout << arr[it] << ' ';

    return 0;
}