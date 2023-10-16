#include <iostream>

using namespace std;

const int MAX = 1001;

int main() {
    int N;
    cin >> N;

    int arr[MAX];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int dp[MAX];
    int cnt = 1;

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        cnt = max(cnt, dp[i]);
    }
    cout << cnt;

    return 0;
}