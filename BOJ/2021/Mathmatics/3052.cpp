#include <iostream>

using namespace std;

int main() {
    int input[10], result[42] = { }, cnt = 0;
    for (int i = 0; i < 10; i++)
        cin >> input[i];

    for (int i = 0; i < 10; i++) {
        int idx = input[i] % 42;
        result[idx]++;
    }

    for (int i = 0; i < 42; i++) {
        if (result[i] > 0)
            cnt++;
        else
            continue;
    }
    cout << cnt;

    return 0;
}