#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[105];
vector<int> Graph[105];
int cnt = 0;

void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;

    while(!Q.empty()) {
        int n = Q.front();
        Q.pop();
        cnt++;

        for (int i=0; i<Graph[n].size(); i++) {
            int idx = Graph[n][i];

            if (!visited[idx]) {
                Q.push(idx);
                visited[idx] = true;
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    while(E-->0) {
        int x,y;
        cin >> x >> y;

        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    BFS(1);

    cout << cnt-1 << '\n';

    return 0;
}