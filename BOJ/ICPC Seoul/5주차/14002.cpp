#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1005

using namespace std;

int N, idx=0;
int arr[MAX], dp[MAX];
vector<int> total;

void SOL() {
    for (int target=0; target<N; target++) {
        dp[target] = 1;

        for (int j=0; j<target; j++) {
            if (arr[target] > arr[j]) {
                dp[target] = max(dp[j]+1, dp[target]);
            }
        }
        idx = max(idx, dp[target]);
    }
    // DP 배열 구성

    for (int i=N-1; i>=0; i--) {
        if (idx==dp[i]) {
            total.push_back(arr[i]);
            idx--;
        }
    }
    // total벡터에 넣음 / 이후에 오름차순으로 재정렬 필요 -> 출력조건
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> N;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        arr[i] = a;
    }
    // 입력

    SOL();

    sort(total.begin(), total.end());

    cout << total.size() << '\n';
    for (int ans : total) cout << ans << ' ';
    cout << '\n';
    // 출력

    return 0;
}