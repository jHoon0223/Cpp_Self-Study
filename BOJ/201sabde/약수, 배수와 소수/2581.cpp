#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> total;

int cnt=0;

bool isF(int a) {
    for (int i=2; i<a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N,M;
    cin >> M >> N;

    if (N==1) {
        cout << -1 << '\n';
        return 0;
    }

    for (int target=M; target<=N; target++) {
        if (target==1) continue;

        if (isF(target)) {
            total.push_back(target);
            cnt += target;
        }
        else continue;
    }

    sort(total.begin(), total.end());

    if (cnt==0) cout << -1 << '\n';
    else cout << cnt << '\n' << total[0] << '\n';

    return 0;
}