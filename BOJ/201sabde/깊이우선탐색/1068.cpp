#include <iostream>
#include <vector>

#define MAX 51

using namespace std;

int N,K;
int cnt;
vector<int> Graph[MAX];
bool visited[MAX];

void DFS(int start) {
    visited[start] = true;

    if (start==K) return;

    if (Graph[start].empty()) {
        cnt++;
        return;
    }

    for (int i=0; i<Graph[start].size(); i++) {
        int idx = Graph[start][i];

        if (idx==K) continue;

        if (!visited[idx]) {
            DFS(idx);
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int root;
    cin >> N;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        if (a==-1) {
            root = i;
            continue;
        }
        
        Graph[a].push_back(i);
    }

    cin >> K;

    Graph[K].clear();
    for (int i=0; i<N; i++) {
        for (int j=0; j<Graph[i].size(); j++) {
            if (Graph[i][j] == K)
                Graph[i].erase(Graph[i].begin() + j);
        }
    }

    DFS(root);
    cout << cnt << '\n';

    return 0;
}