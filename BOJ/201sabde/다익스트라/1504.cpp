#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 805
#define INF 987654321

using namespace std;

int V,E, v1,v2;
vector<pair<int,int>> Graph[MAX];

// 다익스트라 알고리즘 함수
vector<int> dijkstra(int start) {
    vector<int> dist(V+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode]) continue;

        for (auto& edge : Graph[currentNode]) {
            int nextNode = edge.first;
            int weight = edge.second;

            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    return dist;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> V >> E;

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));
    }
    cin >> v1 >> v2;

    vector<int> costA = dijkstra(1);
    vector<int> costv1 = dijkstra(v1);
    vector<int> costv2 = dijkstra(v2);

    int total1 = costA[v1] + costv1[v2] + costv2[V];
    int total2 = costA[v2] + costv2[v1] + costv1[V];

    if ((total1 >= INF && total2 >= INF) || total1 <= 0 || total2 <= 0) cout << -1 << '\n';
    else cout << min(total1, total2) << '\n';

    return 0;
}