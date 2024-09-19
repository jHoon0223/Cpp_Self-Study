#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define MAX 25

using namespace std;

int N, cnt=0;

int matched[MAX];
bool visited[MAX];

vector<int> input;
vector<int> mid_input;
vector<int> v[MAX];

set<int> total;

bool isF(int a, int b) {
    int target = a+b;
    for (int i=2; i<target; i++)
        if (target % i == 0) return false;

    return true;
}

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

    cin >> N;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        input.push_back(a);
    }
    sort(input.begin(), input.end());

    int target = input[0];
    for (int tmp : input) {
        if (target == tmp) continue;

        if (isF(target, tmp)) mid_input.push_back(tmp);
        else continue;
    }

    for (int a : mid_input) {
        cnt = 0;
        fill(matched, matched+MAX, 0);

        for (int _target : input) {
            if (_target == target) continue;
            else if (_target == a) continue;
            else {
                for (int __target : input) {
                    if (__target == target) continue;
                    else if (__target == a) continue;
                    else {
                        if (isF(_target, __target))
                            v[_target].push_back(__target);
                    }
                }
            }
        }

        for (int t=0; t<N; t++) {
            if (input[t] == target) continue;
            else if (input[t] == a) continue;

            fill(visited, visited+MAX, false);
            matched[target] = a;
            visited[a] = true;

            if (DFS(input[t])) cnt++;
        }

        if (cnt+1 == N/2) total.insert(matched[target]);
        else continue;
    }

    if (total.empty()) cout << -1 << '\n';
    else {
        for (int a : total) cout << a << ' ';
        cout << '\n';
    }

    return 0;
}