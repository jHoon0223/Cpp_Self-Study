#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 2002

using namespace std;

int V,E;
bool visited[MAX];
vector<int> Graph[MAX];

void DFS(int curr) {
    visited[curr] = true;

    for (int next : Graph[curr])
        if (!visited[next]) DFS(next);
}

void BFS(int curr) {
    queue<int> q;
    q.push(curr);
    visited[curr] = true;

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        for (int next : Graph[idx]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
    }

    int Q;
    cin >> Q;
    for (int i=0; i<Q; i++) {
        int a,b;
        cin >> a >> b;

        fill(visited, visited+V, false);
        //DFS(a);
        BFS(a);
        if (visited[b]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}