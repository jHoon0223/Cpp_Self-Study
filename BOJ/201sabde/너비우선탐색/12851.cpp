#include <iostream>
#include <queue>

#define MAX 100005

using namespace std;

int N,K;
queue<pair<int,int>> Q;
bool visited[MAX];
int res1, resCnt;

void F(int a,int c) {
    visited[a] = true;
    Q.push(make_pair(a,c));

    while (!Q.empty()) {
        int n = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        visited[n] = true;

        if (res1 && res1==cnt && n==K) {
            resCnt++;
        }   //재방문

        if (!res1 && n==K) {
            res1 = cnt;
            resCnt++;
        }   //첫방문        

        if (n+1>=0 && n+1<MAX && !visited[n+1]) {
            Q.push(make_pair(n+1, cnt+1));
        }
        if (n-1>=0 && n-1<MAX && !visited[n-1]) {
            Q.push(make_pair(n-1, cnt+1));
        }
        if (n*2>=0 && n*2<MAX && !visited[n*2]) {
            Q.push(make_pair(n*2, cnt+1));
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> N >> K;

    F(N,0);

    cout << res1 << '\n' << resCnt << '\n';

    return 0;
}