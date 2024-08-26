#include <iostream>
#include <vector>
#include <queue>

#define MAX 1002

using namespace std;

int V,E,K;

vector<pair<int,int>> Graph[MAX];
priority_queue<int> K_pq[MAX];

void dijkstra(int start) {
    K_pq[start].push(0);
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(start,0));

    while (!pq.empty()) {
        int curr = pq.top().first;
        int dist = -pq.top().second;
        pq.pop();

        for (int i=0; i<Graph[curr].size(); i++) {
            int newCurr = Graph[curr][i].first;
            int newDist = dist + Graph[curr][i].second;

            if (K_pq[newCurr].size() < K) {
                K_pq[newCurr].push(newDist);
                pq.push(make_pair(newCurr, -newDist));
            }   //  큐의 사이즈가 K를 넘기는건 무의미하므로, K보다 작을때만 실행
            else if (K_pq[newCurr].top() > newDist) {
                K_pq[newCurr].pop();
                K_pq[newCurr].push(newDist);
                pq.push(make_pair(newCurr, -newDist));
            }   // 만약 새로운 경로의 크기가 top보다 더 작은 수라면,
        }       // 해당 top을 pop 시키고, 더 작은 수를 집어넣음.
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> V >> E >> K;

    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        Graph[a].push_back(make_pair(b,c));
    }

    dijkstra(1);

    for (int i=1; i<=V; i++) {
        if (K_pq[i].size() != K) cout << -1 << '\n';
        else cout << K_pq[i].top() << '\n';
    }

    return 0;
}