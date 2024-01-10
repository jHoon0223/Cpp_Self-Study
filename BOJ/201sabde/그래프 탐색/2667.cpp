#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 26

using namespace std;

int N;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false };
vector<int> V;

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };
            //상  하  좌  우 

void BFS(int x, int y) {
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    int cnt = 0;
    cnt++;

    while(!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N && visited[newX][newY] == false && arr[newX][newY] == 1) {
                Q.push(make_pair(newX, newY));
                visited[newX][newY] = true;
                cnt++;
            }
        }
    }
    V.push_back(cnt);
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf("%1d", &arr[i][j]);

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (visited[i][j] == false && arr[i][j] == 1) BFS(i,j);

    sort(V.begin(), V.end());
    cout << V.size() << '\n';
    for (int idx : V) cout << idx << '\n';

    return 0;
}