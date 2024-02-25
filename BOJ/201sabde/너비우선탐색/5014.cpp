#include <iostream>
#include <queue>

#define MAX 1000001

using namespace std;

queue<pair<int,int>> Q;
bool visited[MAX] = { false };

int F,S,G,U,D;

int BFS(int a, int c) {
    visited[a] = true;
    Q.push(make_pair(a,c));

    while (!Q.empty()) {
        int n = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if (n == G) return cnt;

        if (n+U>=1 && n+U<=F && !visited[n+U]) {
            visited[n+U] = true;
            Q.push(make_pair(n+U, cnt+1));
        }
        if (n-D>=1 && n-D<=F && !visited[n-D]) {
            visited[n-D] = true;
            Q.push(make_pair(n-D, cnt+1));
        }
    }

    return -1;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> F >> S >> G >> U >> D;

    int total = BFS(S,0);
    total == -1 ? cout << "use the stairs\n" : cout << total << '\n';

    return 0;
}