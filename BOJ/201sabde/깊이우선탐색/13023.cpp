#include <iostream>
#include <vector>

#define MAX 2002

using namespace std;

int V,E;
vector<int> Graph[MAX];
bool visited[MAX] = { false };
bool flag = false;

void DFS(int start, int cnt) {
    if (cnt==4) {
        flag = true;
        return;
    }

    visited[start] = true;

    for (int i=0; i<Graph[start].size(); i++) {
        int idx = Graph[start][i];

        if (!visited[idx]) {
            DFS(idx, cnt+1);

            visited[idx] = false;
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            DFS(i,0);
            visited[i] = false;
        }

        if (flag) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';

    return 0;
}