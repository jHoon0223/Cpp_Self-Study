#include <iostream>

using namespace std;

#define MAX 100

int V, E, start;
int arr[MAX][MAX] = { 0 };
bool visited[MAX] = { false };

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

int main() {
    cin >> V >> E >> start;

    for (int i = 1; i <= E; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    DFS(start);

    return 0;
}