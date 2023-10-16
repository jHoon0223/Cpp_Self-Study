#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int V, E, start;
int arr[MAX][MAX];
bool visited[MAX];

void DFS(int start) {
    cout << start << " ";
    visited[start] = true;
    for (int i = 1; i <= V; i++) {
        if (arr[start][i] && !visited[i])
            DFS(i);
        if (i == V)
            return;
    }
}
void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int next = q.front();
        visited[next] = true;
        cout << next << " ";
        q.pop();

        for (int i = 1; i <= V; i++) {
            if (arr[next][i] && !visited[i]) {
                visited[i]= true;
                q.push(i);
            }
        }
    }
}
void clear() {
    for (int i = 0; i < MAX; i++)
        visited[i] = false;
}

int main() {
    cin >> V >> E >> start;

    for (int i = 1; i <= E; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    DFS(start);
    cout << endl;
    clear();
    BFS(start);
    cout << endl;

    return 0;
}