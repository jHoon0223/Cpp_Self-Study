#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001

using namespace std;

bool visited[MAX] = { false, };
vector<int> Graph[MAX];
int total[MAX];
int cnt = 0;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cnt++;
    total[start] = cnt;

    while(!q.empty()) {
        int n = q.front();
        q.pop();

        for (int i=0; i<Graph[n].size(); i++) {
            int idx = Graph[n][i];

            if (!visited[idx]) {
                q.push(idx);
                visited[idx] = true;

                cnt++;
                total[idx] = cnt;
            }
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N,M,start;
    cin >> N >> M >> start;

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
		sort(Graph[i].begin(), Graph[i].end(), greater<>());

    BFS(start);

    for (int ans=1; ans<=N; ans++) 
        cout << total[ans] << '\n';

    return 0;
}