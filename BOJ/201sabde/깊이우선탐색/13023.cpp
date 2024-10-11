#include <iostream>
#include <vector>

#define MAX 2002

using namespace std;

int V,E;
vector<int> Graph[MAX];
bool visited[MAX] = { false };
bool flag = false;

void DFS(int curr, int cnt) {
    if (cnt == 4) {
        flag = true;
        return;
    }

    visited[curr] = true;
    for (int next : Graph[curr]) {
        if (!visited[next]) {
            DFS(next, cnt+1);
            visited[next] = false;
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