#include <stdio.h>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int N;
vector<int> vR, vG, vB;
char arr[MAX][MAX];
bool visited[MAX][MAX] = { false };

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };
            //상  하  좌  우 

void BFS(int x, int y, char c) {
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
                if (arr[newX][newY] == c) {
                    Q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i=0; i<N; i++)
        scanf("%s", arr[i]);

    int cntR=0, cntG=0, cntB=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j] == false && arr[i][j] == 'R') {
                BFS(i,j,'R');
                cntR++;
            }
            else if (visited[i][j] == false && arr[i][j] == 'G') {
                BFS(i,j,'G');
                cntG++;
            }
            else if (visited[i][j] == false && arr[i][j] == 'B') {
                BFS(i,j,'B');
                cntB++;
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j] = false;

            if (arr[i][j] == 'G') 
                arr[i][j] = 'R';
        }
    }

    int  cntRR=0, cntBB=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j] == false && arr[i][j] == 'B') {
                BFS(i,j,'B');
                cntBB++;
            }
            else if (visited[i][j] == false && arr[i][j] == 'R') {
                BFS(i,j,'R');
                cntRR++;
            }
        }
    }

    int total1 = cntR + cntG + cntB;
    int total2 = cntRR + cntBB;

    printf("%d %d\n", total1, total2);

    return 0;
}