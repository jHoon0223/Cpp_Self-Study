#include <iostream>
#include <queue>

#define MAX 51

using namespace std;

int w,h;
queue<pair<int,int>> Q;
bool visited[MAX][MAX] = { false };
int arr[MAX][MAX] = { 0 };

int Dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int Dy[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
            //상 하  좌  우     대각선 처리 

void reset(int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j] = false;
            arr[i][j] = 0;
        }
    }
}
//초기화 함수

void BFS(int x, int y) {
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    while (!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<8; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if ((newX >= 0 && newX < w) && (newY >= 0 && newY < h)) {
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

    while(1) {
        cin >> h >> w;

        if (w==0 && h==0) return 0;

        int cnt=0;
        reset(w,h);

        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                int a;
                cin >> a; 
                arr[i][j] = a;
                //섬과 바다 지도 입력
            }
        }

        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
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