#include <iostream>
#include <deque>

using namespace std;

#define MAX 1005

int arr[MAX][MAX];
int N,M,noTomato;

struct T {
    int x;
    int y;
}typedef t;

t tArr[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

deque<pair<int,int>> dq;

bool isRipe() {
    int size = N*M - noTomato;
    int cnt = 0;

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (arr[i][j] == 1) cnt++;
        }
    }

    return size == cnt;
}

int TOMATO(void) {
    int day = 0;

    if (dq.empty())
        return -1;
    while (!dq.empty()) {
        int size = dq.size();

        for (int i = 0; i < size; i++) {
            int y = dq.front().first;
            int x = dq.front().second;

            for (int i = 0; i < 4; i++) {
                int newY = y + tArr[i].y;
                int newX = x + tArr[i].x;

                if (newX >= 0 && newX < N && newY >= 0 && newY < M && arr[newY][newX] == 0) {
                    arr[newY][newX] = 1;
                    dq.push_back(make_pair(newY, newX));
                }
            }
            dq.pop_front();

            if (dq.size() == 0 && isRipe())
                return day; //모두 익은 상태면 day return
            else if (dq.size() == 0 && !isRipe())
                return -1;  //모두 익힐 수 없는 상태면 -1 return
        }
        day++;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) dq.push_back(make_pair(i,j));
            else if (arr[i][j] == -1) noTomato++;
        }
    }

    if (dq.size() == N*M - noTomato) cout << 0 << '\n';
    else cout << TOMATO() << '\n';

    return 0;
}