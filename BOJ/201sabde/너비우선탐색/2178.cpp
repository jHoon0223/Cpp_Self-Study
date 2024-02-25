#include <stdio.h>
#include <queue>

#define MAX 101

using namespace std;

int N,M;
char arr[MAX][MAX];
bool visited[MAX][MAX] = { false };
int dist[MAX][MAX];

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };
            //상  하  좌  우 

void BFS(int x, int y) {
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    dist[x][y] = 1;

    while(!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if ((newX >= 0 && newX < N) && (newY >= 0 && newY < M)) {
                if (visited[newX][newY] == false && arr[newX][newY] == '1') {
                    Q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;

                    dist[newX][newY] = dist[X][Y] + 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) scanf("%s", arr[i]);

    BFS(0,0);
    printf("%d\n", dist[N-1][M-1]);

    return 0;
}