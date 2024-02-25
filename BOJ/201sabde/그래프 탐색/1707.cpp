#include <iostream>
#include <queue>
#include <vector>

#define MAX 200001
#define RED 1
#define BLUE 2

using namespace std;

int V,E;
vector<int> Graph[MAX];
int visited[MAX] = { 0 };

void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = RED;

    int color = RED;
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();

        if (visited[curr] == RED) color = BLUE;
        else if (visited[curr] == BLUE) color = RED;

        for (int i=0; i<Graph[curr].size(); i++) {
            int idx = Graph[curr][i];

            if (!visited[idx]) {
                Q.push(idx);
                visited[idx] = color;
            }
        }
    }
}

bool isBipartite() {
    for (int curr=1; curr<=V; curr++) {
        for (int j=0; j<Graph[curr].size(); j++) {
            int next = Graph[curr][j];
            
            if (visited[curr] == visited[next]) return false;
        }
    }
    return true;
}

void clear() {
    for (int i=0; i<=V; i++) {
        Graph[i].clear();
        visited[i] = 0;
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    while (K-->0) {
        cin >> V >> E;

        for (int i=0; i<E; i++) {
            int a,b;
            cin >> a >> b;

            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }

        for (int i=1; i<=V; i++) {
            if (!visited[i]) {
                BFS(i);
            }
        }

        isBipartite() ? cout << "YES" << '\n' : cout << "NO" << '\n';

        clear();
    }

    return 0;
}