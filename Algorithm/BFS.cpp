#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

int V, E, start;
int arr[MAX][MAX] = { 0 };
bool visited[MAX] = { false };

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

int main() {
    cin >> V >> E >> start;

    for (int i = 1; i <= E; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    BFS(start);

    return 0;
}