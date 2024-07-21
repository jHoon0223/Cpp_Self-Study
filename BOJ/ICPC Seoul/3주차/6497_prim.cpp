#include <iostream>
#include <vector>
#include <queue>

#define MAX 200001

using namespace std;

int V,E;
vector<pair<int,int>> Graph[MAX];
bool visited[MAX] = { false };

vector<int> ans;

int prim() {
    priority_queue<pair<int,int>> pq;
    int total = 0;

    pq.push(make_pair(0,0));

    while (!pq.empty()) {
        while (!pq.empty() && visited[pq.top().second]) pq.pop();
        if (pq.empty()) break;

        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        visited[curr] = true;
        total += cost;

        for (int j=0; j<Graph[curr].size(); j++) {
            int next = Graph[curr][j].first;
            int newCost = Graph[curr][j].second;

            if (visited[next] == false)
                pq.push(make_pair(-newCost, next));
        }
    }

    return total;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    while (1) {
        cin >> V >> E;

        if (V==0 && E==0) break;

        int sum=0;
        for (int i=0; i<E; i++) {
            int x,y,z;
            cin >> x >> y >> z;

            Graph[x].push_back(make_pair(y,z));
            Graph[y].push_back(make_pair(x,z));

            sum += z;
        }

        ans.push_back(sum - prim());

        memset(visited, false, sizeof(visited));  // visited 배열 초기화
        for (int i=0; i<V; i++) Graph[i].clear();   // Graph 초기화
    }

    for (int a : ans) cout << a << '\n';

    return 0;
}