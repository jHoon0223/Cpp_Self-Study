#include <iostream>
#include <set>
#include <algorithm>

#define MAX 101

using namespace std;

int start;
bool flag = false;
int arr[MAX];
bool visited[MAX];
set<int> total;

void DFS(int curr) {
    if (visited[curr]) {
        if (start == curr) {
            flag = true;
            total.insert(start);
        }
        return;
    }
    visited[curr] = true;
    DFS(arr[curr]);

    if (flag) {
        total.insert(curr);
        total.insert(arr[curr]);
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i=1; i<=N; i++)
        cin >> arr[i];

    for (int target=1; target<=N; target++) {
        start = target;
        visited[target] = true;

        DFS(arr[target]);
        
        fill(visited, visited+MAX, false);
        flag = false;
    }

    cout << total.size() << '\n';
    for (int ans : total) cout << ans << '\n';

    return 0;
}