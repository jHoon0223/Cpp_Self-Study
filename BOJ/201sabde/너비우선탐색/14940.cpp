#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 1001

using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];
int N,M, _x, _y;

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };
            //상  하  좌  우 

void BFS(int x, int y) {
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

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && visited[newX][newY] == false) {
                if (arr[newX][newY] == 1) {
                    Q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;

                    arr[newX][newY] += arr[X][Y];
                }
            }
        }        
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int a;
            cin >> a;

            if (a == 2) {
                _x = i; _y = j;
            }
            arr[i][j] = a;
        }
    }

    BFS(_x, _y);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] == 0) cout << 0 << ' ';
            else if (arr[i][j] == 1) cout << -1 << ' ';
            else cout << arr[i][j] - 2 << ' ';
        }
        cout << '\n';
    }

    return 0;
}