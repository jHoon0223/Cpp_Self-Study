#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 52

using namespace std;

int N;
int shark[52][3];
int matched[MAX];
bool visited[MAX];
vector<int> v[MAX];

bool DFS(int curr) {
    if (visited[curr]) return false;

    visited[curr] = true;

    for (int next : v[curr]) {
        if (!matched[next] || matched[next] != curr && DFS(matched[next])) {
            matched[next] = curr;
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;

    for (int target=1; target<=N; target++) {
        cin >> shark[target][0] >> shark[target][1] >> shark[target][2];
    }

    for (int target=1; target<=N; target++) {
        for (int i=1; i<=N; i++) {
            if (target == i) continue;

            if (shark[target][0] == shark[i][0]
                && shark[target][1] == shark[i][1] 
                && shark[target][2] == shark[i][2]) {
                    v[target>i ? i:target].push_back(target>i ? target : i);
                    continue;
            }

            if (shark[target][0] >= shark[i][0] 
                && shark[target][1] >= shark[i][1] 
                && shark[target][2] >= shark[i][2]) {
                v[target].push_back(i);
            }
        }
    }

    int total = 0;
    for (int target=1; target<=N; target++) {
        for (int i=0; i<2; i++) {
            fill(visited, visited+MAX, false);
            DFS(target);
        }
    }

    for (int i=1; i<=N; i++) 
        if (matched[i]) total++;

    cout << N - total << '\n';

    return 0;
}