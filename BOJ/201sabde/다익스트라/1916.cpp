#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 999999999

using namespace std;

vector<pair<int,int>> Graph[MAX];
int cost[MAX];

void dijkstra(int start) {
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
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int V,E;
    cin >> V >> E;

    for (int i=1; i<=V; i++) cost[i] = INF;

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(b,c));
    }

    int startingPoint, destination;
    cin >> startingPoint >> destination;

    dijkstra(startingPoint);

    cout << cost[destination] << '\n';
    //for (int i=1; i<=V; i++) cout << cost[i] << ' ';

    return 0;
}