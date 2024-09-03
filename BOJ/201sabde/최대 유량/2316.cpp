#include <iostream>
#include <vector>
#include <queue>

#define MAX 802
#define out 400
#define INF 999999

using namespace std;

int N,P, total=0;
int capacity[MAX][MAX], flow[MAX][MAX], visited[MAX];
vector<int> v[MAX];

void maxFlow(int start, int end) {
    while (1) {
        fill(visited, visited+MAX, -1);

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : v[curr]) {
                if (capacity[curr][next] - flow[curr][next] > 0 && visited[next] == -1) {
                    q.push(next);
                    visited[next] = curr;

                    if (next == end) break;
                }
            }
        }

        if (visited[end] == -1) break;

        int tmp = INF;
        for (int i=end; i!=start; i=visited[i]) 
            tmp = min(tmp, capacity[visited[i]][i] - flow[visited[i]][i]);
        
        for (int i=end; i!=start; i=visited[i]) {
            flow[visited[i]][i] += tmp;
            flow[i][visited[i]] -= tmp;
        }

        total += tmp;
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> P;

    for (int i=1; i<=N; i++) {
        v[i].push_back(i + out);
        v[i + out].push_back(i);
        capacity[i][i+out] = 1;
    }

    for (int i=0; i<P; i++) {
        int from, to;
        cin >> from >> to;

        v[to].push_back(out + from);
        v[out + from].push_back(to);
        capacity[out + from][to] = 1;

        v[to + out].push_back(from);
        v[from].push_back(to + out);
        capacity[to + out][from] = 1;
    }

    maxFlow(1 + out, 2);

    cout << total << '\n';

    return 0;
}