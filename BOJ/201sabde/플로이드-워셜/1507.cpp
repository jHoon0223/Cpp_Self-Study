#include <iostream>

#define MAX 21

using namespace std;

int N;
int arr[MAX][MAX];
int _arr[MAX][MAX];
bool flag = true;

void F() {
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (k==i || k==j) continue;

                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    flag = false;
                    return;
                }
                else if (arr[i][j] == arr[i][k] + arr[k][j])
                    _arr[i][j] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
            _arr[i][j] = arr[i][j];
        }
    }

    F();

    if (!flag) cout << -1 << '\n';
    else {
        int sum=0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                sum += _arr[i][j];
            }
        }
        cout << sum / 2 << '\n';
    }

    return 0;
}