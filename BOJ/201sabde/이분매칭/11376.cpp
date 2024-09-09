#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int matched[MAX];
bool visited[MAX];
vector<int> v[MAX];

bool DFS(int curr) {
    for (int next : v[curr]) {
        if (visited[next]) continue;

        visited[next] = true;

        if (matched[next] == 0 || DFS(matched[next])) {
            matched[next] = curr;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for (int target=1; target<=N; target++) {
        int size;
        cin >> size;

        while (size-->0) {
            int a;
            cin >> a;
            v[target].push_back(a);
        }
    }

    int total = 0;
    for (int target=1; target<=N; target++) {
        for (int i=0; i<2; i++) {
            fill(visited, visited+MAX, false);
            if (DFS(target)) total++;
        }
    }
    cout << total << '\n';

    return 0;
}