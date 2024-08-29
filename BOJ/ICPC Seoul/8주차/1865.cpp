#include <iostream>
#include <string>
#include <vector>

#define MAX 999999

using namespace std;

int N,M,W;

bool bellmanFord(int N, vector<pair<int, pair<int, int>>> &edges) {
    vector<int> dist(N+1, MAX);
    dist[1] = 0;

    for (int i = 1; i < N; i++) {
        for (auto &edge : edges) {
            int s = edge.first;
            int e = edge.second.first;
            int t = edge.second.second;

            if (dist[e] > dist[s] + t) dist[e] = dist[s] + t;
        }
    }

    for (auto &edge : edges) {
        int s = edge.first;
        int e = edge.second.first;
        int t = edge.second.second;

        if (dist[e] > dist[s] + t) return true;
    }

    return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int TC;
    cin >> TC;

    int s, e, t;
    while (TC-->0) {
        cin >> N >> M >> W;

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            edges.push_back({ s, {e, t} });
            edges.push_back({ e, {s, t} });
        }
        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;
            edges.push_back({ s, {e, -t} });
        }

        if (bellmanFord(N, edges)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}