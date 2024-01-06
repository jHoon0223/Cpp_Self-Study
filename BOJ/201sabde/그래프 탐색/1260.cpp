#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Graph[1005];
bool D_visited[1005];
bool B_visited[1005];

void DFS(int start) {
    D_visited[start] = true;

    cout << start << ' ';

    for (int i=0; i<Graph[start].size(); i++) {
        int idx = Graph[start][i];

        if (!D_visited[idx]) DFS(idx);
    }
}

void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    B_visited[start] = true;

    while(!Q.empty()) {
        int n = Q.front();
        Q.pop();
        cout << n << ' ';

        for (int i=0; i<Graph[n].size(); i++) {
            int idx = Graph[n][i];

            if (!B_visited[idx]) {
                Q.push(idx);
                B_visited[idx] = true;
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N,M,V;
    cin >> N >> M >> V;

    while(M-->0) {
        int x,y;
        cin >> x >> y;

        Graph[x].push_back(y);
        Graph[y].push_back(x);

        sort(Graph[x].begin(), Graph[x].end());
        sort(Graph[y].begin(), Graph[y].end());
    }

    DFS(V);
    cout << '\n';
    BFS(V);
    cout << '\n';

    return 0;
}