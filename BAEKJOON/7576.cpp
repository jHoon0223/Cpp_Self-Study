#include <iostream>
#include <deque>

using namespace std;

#define MAX 1001

struct XY {
    int y;
    int x;
}typedef xy;

xy xyDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

deque<pair<int, int>> dq;
int arr[MAX][MAX];
int M, N, noTomato;

bool Ripe(void) {
    int size = M * N - noTomato, cnt = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1)
                cnt++;
        }
    }
    return size == cnt;
}
int BFS(void) {
    int day = 0;

    if (dq.empty())
        return -1;
    while (!dq.empty()) {
        int size = dq.size();

        for (int i = 0; i < size; i++) {
            int y = dq.front().first;
            int x = dq.front().second;

            for (int i = 0; i < 4; i++) {
                int newY = y + xyDir[i].y;
                int newX = x + xyDir[i].x;

                if (newX >= 0 && newX < N && newY >= 0 && newY < M && arr[newY][newX] == 0) {
                    arr[newY][newX] = 1;
                    dq.push_back(make_pair(newY, newX));
                }
            }
            dq.pop_front();

            if (dq.size() == 0 && Ripe())
                return day; //모두 익은 상태면 day return
            else if (dq.size() == 0 && !Ripe())
                return -1;  //모두 익힐 수 없는 상태면 -1 return
        }
        day++;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
                dq.push_back(make_pair(i,j));
            else if (arr[i][j] == -1)
                noTomato++;
        }
    }

    if (dq.size() == N * M - noTomato)
        cout << 0;  //이미 다 익음
    else {
        int total = BFS();
        cout << total;
    }// BFS 호출

    return 0;
}