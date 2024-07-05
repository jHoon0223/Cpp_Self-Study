#include <stdio.h>
#include <iostream>

#define MAX 301

using namespace std;

int N,M;
int x1,y11,x2,y2;
char arr[MAX][MAX];
int visited[MAX][MAX] = { false };
bool flag;

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y, int i) {
    visited[x][y] = i;

    if (arr[x][y] == '#') {
        cout << i << endl;
        flag = true;
        return;
    }

    if (arr[x][y] == '1') {
        arr[x][y] = '0';
        return;
    }

    for (int j=0; j<4; j++) {
        int newX = x + Dx[j];
        int newY = y + Dy[j];

        if (newX == 0 || newY == 0 || newX == N+1 || newY == M+1) continue;
        if (visited[newX][newY] == i) continue;

        DFS(newX, newY, i);
    }
}

int main() {
    cin >> N >> M;
    cin >> x1 >> y11 >> x2 >> y2;

    for (int i=1; i<=N; i++) {
		scanf("%s", arr[i] + 1);
	}

    arr[x1][y11] = '0';
    for (int i=1; ; i++) {
        DFS(x1, y11, i);
        
        if (flag) return 0;
    }

    return 0;
}