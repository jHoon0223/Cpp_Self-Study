#include <iostream>
#include <queue>

#define MAX 601

using namespace std;

int N,M;
int cnt;
char arr[MAX][MAX];
bool visited[MAX][MAX] = { false };

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };

int startX, startY;

void whereIsStartingP() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] == 'I') {
                startX = i;
                startY = j;
                return;
            }
        }
    }
}

int BFS(int x, int y) {
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    while (!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if (newX<0 || newX>=N || newY<0 || newY>=M) continue;
            if (arr[newX][newY] == 'X') continue;

            if (!visited[newX][newY] && arr[newX][newY] == 'P')
                cnt++;

            visited[newX][newY] = true;
            Q.push(make_pair(newX, newY));
        }
    }

    return cnt;
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    whereIsStartingP();

    int total = BFS(startX, startY);

    total ? cout << total << '\n' : cout << "TT\n";

    return 0;
}