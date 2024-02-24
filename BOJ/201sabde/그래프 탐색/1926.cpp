#include <iostream>
#include <queue>

#define MAX 501

using namespace std;

int N,M;
int areaCnt, maxArea;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false };
vector<int> v;

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, 1, -1 };

int BFS(int x, int y) {
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    int cnt=0;
    cnt++;

    while (!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if ((newX>=0 && newX<M) && (newY>=0 && newY<N) &&
            (visited[newX][newY] == false)) {
                if (arr[newX][newY] == 1) {
                    Q.push(make_pair(newX,newY));
                    visited[newX][newY] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int a;
            cin >> a;

            arr[j][i] = a;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visited[i][j] == false && arr[i][j] == 1) {
                areaCnt++;
                maxArea = max(maxArea, BFS(i,j));
            }
        }
    }

    cout << areaCnt << '\n' << maxArea << '\n';

    return 0;
}