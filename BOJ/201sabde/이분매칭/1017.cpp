#include <iostream>
#include <set>
#include <algorithm>

#define MAX 2000

using namespace std;

int N;

bool prime[MAX];
int input[50];
int matched[50];
bool visited[50];

set<int> total;

bool DFS(int curr) {
    visited[curr] = true;

    for (int next=1; next<N; next++) {
        if (next==curr || !prime[input[curr] + input[next]]) continue;

        if (!matched[next] || (!visited[matched[next]] && DFS(matched[next]))) {
            matched[next] = curr;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    fill(prime, prime+MAX, true);
    for (int i=2; i*i<MAX; i++) {
        if (!prime[i]) continue;
        for (int j=i*i; j<MAX; j+=i) prime[j] = false;
    }
    //  미리 소수 판별

    cin >> N;
    for (int i=0; i<N; i++) cin >> input[i];
    //  input Fin.

    for (int target=1; target<N; target++) {
        if (!prime[input[0] + input[target]]) continue;
        fill(matched, matched+N, 0);
        
        bool flag = true;
        for (int _t=1; _t<N; _t++) {
            if (target == _t) continue;

            fill(visited, visited+N, false);
            visited[target] = true;

            if (DFS(_t) == false) flag = false;
        }

        if (flag) total.insert(input[target]);
    }

    if (total.empty()) cout << -1 << '\n';
    else {
        for (int ans : total) cout << ans << ' ';
        cout << '\n';
    }
    //  Fin.

    return 0;
}