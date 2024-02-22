#include <iostream>
#include <vector>
#include <queue>

#define MAX 100005

using namespace std;

int N;
vector<int> Graph[MAX];
int ANS[MAX];
bool visited[MAX] = { false };

void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;

    while (!Q.empty()) {
        int parent = Q.front();
        Q.pop();

        for (int i=0; i<Graph[parent].size(); i++) {
            int child = Graph[parent][i];

            if (!visited[child]) {
                Q.push(child);
                visited[child] = true;

                ANS[child] = parent;
            }
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    BFS(1);

    for (int i=2; i<=N; i++)
        cout << ANS[i] << '\n';

    return 0;
}