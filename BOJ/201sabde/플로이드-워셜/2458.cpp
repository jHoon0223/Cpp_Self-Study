#include <iostream>

#define MAX 501
#define INF 99999999

using namespace std;

int N,M;
int arr[MAX][MAX];

void floydWarshall() {
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (arr[i][k] != INF && arr[k][j] != INF) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;

        arr[a][b] = 1;
    }

    floydWarshall();

    int cnt=0;
    for (int i=0; i<N; i++) {
        int tmp = 0;
        for (int j=0; j<N; j++) {
            if (i==j) continue;

            if (arr[i][j] != INF || arr[j][i] != INF)
                tmp++;
        }

        if (tmp == N-1) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}