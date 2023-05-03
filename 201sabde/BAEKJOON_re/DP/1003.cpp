#include <iostream>
#include <stdio.h>

using namespace std;

int dp[50] = { 0 };

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
    int T;
    cin >> T;

    while(T-->0) {
        int a;
        cin >> a;

        if (a==0) printf("1 0\n");
        else printf("%d %d\n", fib(a-1), fib(a));
    }

    return 0;
}