#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999999

using namespace std;

int N,M;

vector<pair<int, pair<int,int>>> Graph;
vector<pair<int,int>> dist(101, {INF,INF});

bool bellmanFord(int start) {
    dist[start].first = 0;

    for (int i=1; i<N; i++) {
        for (auto edge : Graph) {
            int s = edge.first;
            int e = edge.second.first;
            int w = edge.second.second;

            if (dist[s].first != INF && dist[e].first > dist[s].first + w) 
                dist[e].first = dist[s].first + w;
        }
    }

    for (auto edge : Graph) {
        int s = edge.first;
        int e = edge.second.first;
        int w = edge.second.second;

        if (dist[s].first != INF && dist[e].first > dist[s].first + w) 
            return false;
    }

    return true;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph.push_back({a, {b,-c}});
    }

    for (int i=1; i<=N; i++) 
        dist[i].second = i;
    sort(dist.begin(), dist.end());

    if (bellmanFord(1)) {
        for (int i=1; i<N; i++) {
            if (dist[i].first == INF) {
                cout << -1 << '\n';
                return 0;
            }
            else cout << dist[i].first << ' ';
        }
        cout << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}