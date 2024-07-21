#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001
#define INF 999999

using namespace std;

int V,E;
vector<pair<int,int>> Graph[MAX];
bool visited[MAX];

int prim() {
    priority_queue<pair<int,int>> pq;
    int total = 0;
    int maxCost = 0;

    pq.push(make_pair(0,1));    //1에서부터 출발. 시작점이므로 가중치는 0

    while (!pq.empty()) {
        while (!pq.empty() && visited[pq.top().second]) pq.pop();
        if (pq.empty()) break;

        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        visited[curr] = true;
        total += cost;
        //cout << cost << ' ';
        maxCost = max(cost, maxCost);

        for (int j=0; j<Graph[curr].size(); j++) {
            int next = Graph[curr][j].first;
            int newCost = Graph[curr][j].second;

            if (visited[next] == false)
                pq.push(make_pair(-newCost, next));
        }
    }

    return total - maxCost;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> V >> E;

    for (int i=0; i<E; i++) {
        int A,B,C;
        cin >> A >> B >> C;

        Graph[A].push_back(make_pair(B,C));
        Graph[B].push_back(make_pair(A,C));
    }

    cout << prim() << '\n';

    return 0;
}