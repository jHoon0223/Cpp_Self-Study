#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500

using namespace std;

int N,K;
int matched[MAX];
bool visited[MAX];

vector<int> v[MAX];

bool DFS(int curr) {
    for (int next : v[curr]) {
        if (visited[next]) continue;

        visited[next] = true;

        if (!matched[next] || DFS(matched[next])) {
            matched[next] = curr;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i=0; i<K; i++) {
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
    }

    int total = 0;
    for (int target=1; target<=N; target++) {
        fill(visited, visited+MAX, false);
        if (DFS(target)) total++;
    }
    cout << total << '\n';

    return 0;
}