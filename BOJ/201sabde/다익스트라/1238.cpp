#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 1001
#define INF 999999999

using namespace std;

vector<pair<int,int>> Graph[MAX];
int costX[MAX];
int cost[MAX];

void dijkstra(int start, int cost[]) {
    cost[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(start,0));

    while (!pq.empty()) {
        int current = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        if (cost[current] < dist) continue;

        for (int i=0; i<Graph[current].size(); i++) {
            int newCurr = Graph[current][i].first;
            int newDist = dist + Graph[current][i].second;

            if (newDist < cost[newCurr]) {
                cost[newCurr] = newDist;
                pq.push(make_pair(newCurr, -newDist));
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int V, E, X;
    cin >> V >> E >> X;

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(b,c));
    }

    for (int i=1; i<=V; i++) costX[i] = INF;
    dijkstra(X, costX);

    for (int i=1; i<=V; i++) {
        for (int i=1; i<=V; i++) cost[i] = INF;

        int target = i;

        dijkstra(target, cost);
        costX[target] += cost[X];
    }

    int max = costX[1];
    for (int i=2; i<=V; i++) {
        if (costX[i] > max) max = costX[i];
        else continue;
    }
    cout << max << '\n';

    return 0;
}