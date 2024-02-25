#include <iostream>
#include <queue>

#define MAX 51

using namespace std;

queue<pair<int,int>> Q;
bool visited[MAX][MAX] = { false };
int arr[MAX][MAX] = { 0 };

int M, N, K;
int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };
            //상  하  좌  우 

void reset(int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

void BFS(int x, int y) {
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if ((newX >= 0 && newX < M) && (newY >= 0 && newY < N)) {
                if (visited[newX][newY] == false && arr[newX][newY] == 1) {
                    Q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T-->0) {
        reset(M,N);
        int cnt=0;
        cin >> M >> N >> K;

        for (int i=0; i<K; i++) {
            int a, b;
            cin >> a >> b;

            arr[a][b] = 1;
        }   //배추 입력

        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if (visited[i][j] == false && arr[i][j] == 1) {
                    BFS(i,j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}