#include <iostream>
#include <vector>
#include <queue>

#define MAX 1005

using namespace std;

vector<int> Graph[MAX];
int visited[MAX];
int cnt = 0;
bool flag;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i=0; i<Graph[n].size(); i++) {
            int idx = Graph[n][i];

            if (!visited[idx]) {
                q.push(idx);
                visited[idx] = true;
                flag = true;
            }
        }
    }
}

int main() {
    int N,M;
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (int i=1; i<=N; i++) {
        if (visited[i]) continue;
        else {
            BFS(i);

            if (flag == true) cnt++;
        }

        if (flag == false) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}