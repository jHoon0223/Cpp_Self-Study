#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int N;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false };

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y, int idx) {
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if ((newX >= 0 && newX < N) && (newY >= 0 && newY < N)
                && visited[newX][newY] == false) {
                if (arr[newX][newY] > idx) {
                    Q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
    }
}
void F(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int a;
            cin >> a;

            arr[i][j] = a;
        }
    }   //배열 입력

    vector<int> total;
    for (int idx=0; idx<101; idx++) {
        F(N);
        int cnt = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (visited[i][j] == false && arr[i][j] > idx) {
                    BFS(i,j,idx);
                    cnt++;
                }
            }
        }

        total.push_back(cnt);
    }
    sort(total.begin(), total.end());

    cout << total.back() << '\n';

    return 0;
}