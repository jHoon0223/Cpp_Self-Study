#include <iostream>

using namespace std;

int dp[25] = { 0 };

int fib(int n) {
    if (n<=1) return n;
    else {
        if (dp[n] != 0) return dp[n];
        else {
            dp[n] = fib(n-1) + fib(n-2);
            return dp[n];
        }
    }
}

int main() {
    int a;
    cin >> a;

    cout << fib(a) << endl;

    return 0;
}