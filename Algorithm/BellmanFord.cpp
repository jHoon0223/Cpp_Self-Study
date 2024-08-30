#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int u, v, weight;
};

bool bellmanFord(int V, int E, int start, vector<Edge>& edges, vector<int>& dist) {
    dist[start] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // 음수 사이클 검출
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            return false;  // 음수 사이클이 존재함
        }
    }

    return true;  // 음수 사이클이 없음
}

int main() {
    int V, E, start;
    cin >> V >> E >> start;

    vector<Edge> edges(E);
    vector<int> dist(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges[i] = {u, v, weight};
    }

    if (bellmanFord(V, E, start, edges, dist)) {
        for (int i = 1; i <= V; i++) {
            if (dist[i] == INF) {
                cout << "INF" << " ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    } else {
        cout << "Negative weight cycle detected" << endl;
    }

    return 0;
}

// 5 8 1
// 1 2 -1
// 1 3 4
// 2 3 3
// 2 4 2
// 2 5 2
// 4 2 1
// 4 3 5
// 5 4 -3

// 4 5 1
// 1 2 1
// 2 3 1
// 3 4 1
// 4 2 -3
// 1 4 10