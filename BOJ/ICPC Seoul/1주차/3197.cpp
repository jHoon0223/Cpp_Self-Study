#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1501

using namespace std;

int R,C;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int meltingDay[MAX][MAX];
int maxDay = 0; // 얼음이 녹는 데 걸리는 최대 일

int Dx[4] = { -1, 1, 0, 0 };
int Dy[4] = { 0, 0, -1, 1 };

vector<pair<int,int>> swan; // 백조의 좌표

bool canMeetSwan(int day) {
    memset(visited, false, sizeof(visited));
    
    queue<pair<int,int>> Q;
    Q.push(make_pair(swan[0].first, swan[0].second));
    visited[swan[0].first][swan[0].second] = true;

    while (!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;

        if (swan[1].first == X && swan[1].second == Y) {
            return true;
        }

        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if (newX < 0 || newY < 0 || newX > R || newY > C) continue;
            if (visited[newX][newY] || meltingDay[newX][newY] > day) continue;

            Q.push(make_pair(newX, newY));
            visited[newX][newY] = true;
        }
    }
    return false;
}

void meltingIce() {
    memset(meltingDay, -1, sizeof(meltingDay));

    queue<pair<int,int>> Q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == '.' || arr[i][j] == 'L') {
                meltingDay[i][j] = 0;
                Q.push(make_pair(i,j));
            }
        }
    }

    while (!Q.empty()) {
        int X = Q.front().first;
        int Y = Q.front().second;

        Q.pop();

        for (int i=0; i<4; i++) {
            int newX = X + Dx[i];
            int newY = Y + Dy[i];

            if (newX < 0 || newY < 0 || newX > R || newY > C) continue;
            if (meltingDay[newX][newY] >= 0) continue;

            Q.push(make_pair(newX,newY));
            meltingDay[newX][newY] = meltingDay[X][Y] + 1;

            if (maxDay < meltingDay[newX][newY]) maxDay = meltingDay[newX][newY];
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> R >> C;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'L') swan.push_back(make_pair(i,j));
        }
    }

    meltingIce();

    int start = 0, end = maxDay;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (canMeetSwan(mid)) end = mid - 1;
        else start = mid + 1;
    }

    cout << start << '\n';

    return 0;
}