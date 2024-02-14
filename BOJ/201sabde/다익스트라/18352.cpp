#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000000
#define INF 999999

using namespace std;

vector<pair<int,int>> Graph[MAX];
int cost[MAX];

void dijkstra(int start) {
    cost[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(start,0));

    while (!pq.empty()) {
        int curr = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        if (cost[curr] < dist) continue;

        for (int i=0; i<Graph[curr].size(); i++) {
            int newCurr = Graph[curr][i].first;
            int newDist = dist + Graph[curr][i].second;

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

    int V,E,K,startingP;
    cin >> V >> E >> K >> startingP;
    
    for (int i=1; i<=V; i++) cost[i] = INF;
    
    for (int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(make_pair(b,1));
    }

    dijkstra(startingP);

    bool flag = false;
    for (int i=1; i<=V; i++) {
        if (cost[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }
    if (flag == false) cout << -1 << '\n';

    return 0;
}