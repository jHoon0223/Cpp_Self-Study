#include <iostream>
#include <vector>

#define MAX 202

using namespace std;

vector<int> v[MAX];
int visited[MAX] = { false };

void DFS(int start) {
    visited[start] = true;

    for (int idx : v[start]) {
        if (!visited[idx]) 
            DFS(idx);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int a;
            cin >> a;

            if (a==1) v[i].push_back(j);
        }
    }

    int dfs_cnt = 0;
    for (int i=0; i<M; i++) {
        int a;
        cin >> a;

        if (!visited[a]) {
            dfs_cnt++;
            DFS(a);
        }
    }

    if (dfs_cnt == 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}