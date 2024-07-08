#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX 1001
#define INF 99999

using namespace std;

int V,E,K;
vector<vector<pair<int, int>>> Graph;
int cost[MAX];

bool dijkstra(int upper) {
    for (int i=0; i<=V; i++) cost[i] = INF;

    cost[1] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(1,0));

    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if (cost[current] < distance) continue;

        for (int i=0; i<Graph[current].size(); i++) {
            int next = Graph[current][i].first;
            int nextDist = distance + (Graph[current][i].second > upper);

            if (nextDist < cost[next]) {
                cost[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
            }
        }
    }

    return cost[V] <= K;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> V >> E >> K;

    Graph.resize(V + 1);

    int start = 0;
    int end = E - 1;

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(b,c));
        Graph[b].push_back(make_pair(a,c));

        end = max(end, c);
    }

    int total = -1, mid;
    while (start <= end) {
        mid = (start + end) / 2;

        if (dijkstra(mid)) {
            total = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << total << '\n';

    return 0;
}