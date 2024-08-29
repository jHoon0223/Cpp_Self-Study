#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100005

using namespace std;

int N,M,R, cnt=0;

vector<int> Graph[MAX];
bool visited[MAX] = { false };
int total[MAX] = { 0 };

void DFS(int idx) {
    visited[idx] = true;

    total[idx] = ++cnt;

    for (int i=0; i<Graph[idx].size(); i++) {
        int target = Graph[idx][i];

        if (!visited[target]) DFS(target);
    }   
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> M >> R;

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (int i=1; i<=N; i++)
        sort(Graph[i].begin(), Graph[i].end());

    DFS(R);

    for (int i=1; i<=N; i++) cout << total[i] << '\n';

    return 0;
}