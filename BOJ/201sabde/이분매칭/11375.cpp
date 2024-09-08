#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1002

using namespace std;

int N, M;

vector<int> v[MAX];
int matched[MAX];
bool visited[MAX];

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

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        int size;
        cin >> size;

        for (int j=0; j<size; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    int total=0;
    for (int i=1; i<=N; i++) {
        fill(visited, visited+MAX, false);
        if (DFS(i)) total++;
    }

    cout << total << '\n';
    
    return 0;
}