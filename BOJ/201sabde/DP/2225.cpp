#include <iostream>

#define MAX 201

using namespace std;

int N,K;
int arr[MAX][MAX];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i=0; i<MAX; i++) {
        arr[1][i] = 1;
    }
    for (int i = 2; i<MAX; i++) {
        arr[i][0] = 1;
    }

    for (int i=2; i<MAX; i++) {
        for (int j=1; j<MAX; j++) {
            arr[i][j] = arr[i][j-1] + arr[i-1][j];
            arr[i][j] %= 1000000000;
        }
    }

    cout << arr[K][N] << '\n';

    return 0;
}