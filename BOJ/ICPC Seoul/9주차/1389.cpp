#include<iostream>

#define MAX 101
#define INF 99999999

using namespace std;

int N, M;
int Graph[MAX][MAX];

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        Graph[a][b] = 1;
        Graph[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && Graph[i][j] != 1) {
                Graph[i][j] = INF;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (Graph[j][i] + Graph[i][k] < Graph[j][k]) {
                    Graph[j][k] = Graph[j][i] + Graph[i][k];
                }
            }
        }
    }

    int total, val = INF;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) {
            tmp += Graph[i][j];
        }

        if (tmp < val) {
            val = tmp;
            total = i;
        }
    }

    cout << total << '\n';

    return 0;
}