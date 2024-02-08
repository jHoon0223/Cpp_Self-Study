#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int INF = 987654321;

int n, m;
vector<pair<int, int>> Graph[1001];
int cost[1001]; // 비용

void dijkstra(int start) {
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int current = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();

		if (cost[current] < dist) continue;

		for (int i = 0; i < Graph[current].size(); i++) {
			int newCurr = Graph[current][i].first;
			int newDist = Graph[current][i].second + dist;

			if (newDist < cost[newCurr]) {
				cost[newCurr] = newDist;
				pq.push({ newCurr, -newDist });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) cost[i] = INF;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		Graph[a].push_back(make_pair(b,c));
	}
	cin >> a >> b;
	dijkstra(a);

	cout << cost[b] << endl;
}