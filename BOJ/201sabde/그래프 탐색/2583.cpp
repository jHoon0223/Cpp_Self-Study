#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int M,N,K;
int arr[MAX][MAX];
bool visited[MAX][MAX] = { false };

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, 1, -1 };

vector<int> total;

void makeArr(int x, int y) {
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            arr[i][j] = 0;
        }
    }
}
void BFS(int x, int y) {
    queue<pair<int,int>> Q;
    Q.push(make_pair(x,y));
    visited[x][y] = true;

    int cnt=0;
    cnt++;

    while(!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if ((newX>=0 && newX<M) && (newY>=0 && newY<N) && 
            (visited[newX][newY] == false)) {
                if (arr[newX][newY] == 0) {
                    Q.push(make_pair(newX,newY));
                    visited[newX][newY] = true;
                    cnt++;
                }
            }
        }
    }
    total.push_back(cnt);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> M >> N >> K;

    makeArr(M,N);

    while(K-->0) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i=x1; i<x2; i++) {
            for (int j=y1; j<y2; j++) {
                arr[j][i] = 1;
            }
        }
    }

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j] == false && arr[i][j] == 0) BFS(i,j);
        }
    }
    sort(total.begin(), total.end());

    // for (int i=0; i<M; i++) {
    //     for (int j=0; j<N; j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << total.size() << '\n';
    for (int aa : total) cout << aa << ' ';
    cout << '\n';

    return 0;
}