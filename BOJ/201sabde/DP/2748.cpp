#include <iostream>
#include <stdio.h>

using namespace std;

long long int dp[100] = { 0, };

long long int fibonacci(int n) {
    if (n <= 1)
        return n;
    else {
        if (dp[n] != 0) return dp[n];
        else {
            dp[n] = fibonacci(n-1) + fibonacci(n-2);
            return dp[n];
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    printf("%lld\n", fibonacci(N));

    return 0;
}