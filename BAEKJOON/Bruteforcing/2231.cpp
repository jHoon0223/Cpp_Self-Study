#include <iostream>

using namespace std;

int F(int n) {
    for (int i = 1; i < n; i++) {
        int total = i, curr = i;

        while(curr > 0) {
            int a = curr%10;
            total += a;

            curr /= 10;
        }
        if (total == n)
            return i;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    cout << F(N);

    return 0;
}