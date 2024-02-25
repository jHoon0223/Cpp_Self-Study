#include <iostream>
#include <queue>

using namespace std;

#define MAX 100005

bool visited[MAX];
queue<pair<int,int>> Q;
int N,K;

int F(int a, int c) {
    visited[a] = true;
    Q.push(make_pair(a,c));
    
    while(!Q.empty()) {
        int n = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if (n == K) return cnt;

        if (n+1>=0 && n+1<MAX && !visited[n+1]) {
            visited[n] = true;
            Q.push(make_pair(n+1, cnt+1));
        }
        if (n-1>=0 && n-1<MAX && !visited[n-1]) {
            visited[n] = true;
            Q.push(make_pair(n-1, cnt+1));
        }
        if (n*2>=0 && n*2<MAX && !visited[n*2]) {
            visited[n*2] = true;
            Q.push(make_pair(n*2, cnt+1));
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    cout << F(N,0) << '\n';

    return 0;
}