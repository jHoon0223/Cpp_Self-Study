#include <iostream>

#define MAX 501

using namespace std;

int M,N;
int arr[MAX][MAX];
int dp[MAX][MAX];

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };

void makeDPtable() {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            dp[i][j] = -1;
        }
    }
}

int DFS(int x, int y) {
    if (x == M-1 && y == N-1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int i=0; i<4; i++) {
        int newX = x + Dx[i];
        int newY = y + Dy[i];

        if (newX<0 || newX>=M || newY<0 || newY>=N) continue;

        if (arr[x][y] > arr[newX][newY]) {
            dp[x][y] += DFS(newX, newY);
        }
    }

    return dp[x][y];
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> M >> N;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    makeDPtable();

    cout << DFS(0,0) << '\n';

    return 0;
}