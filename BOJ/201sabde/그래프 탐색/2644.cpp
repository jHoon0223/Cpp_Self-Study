#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

vector<int> Graph[MAX];
int visited[MAX];

int V, start, dst, E;

int BFS(int start, int end) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        if (n == end) return visited[n];
        
        for (int i=0; i<Graph[n].size(); i++) {
            int idx = Graph[n][i];

            if (visited[idx] == 0) {
                q.push(idx);
                visited[idx] = visited[n] + 1;
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> V >> start >> dst >> E;

    for (int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    cout << BFS(start, dst) << '\n';

    return 0;
}