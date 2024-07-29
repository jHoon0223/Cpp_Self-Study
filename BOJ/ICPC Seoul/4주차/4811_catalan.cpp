#include <iostream>

using namespace std;

long long catalan[31] = {0};

// 카탈랑 수를 계산하는 함수
void Catalan() {
    catalan[0] = 1;

    for (int i = 1; i <= 30; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    // 카탈랑 수 계산
    Catalan();

    while (1) {
        int N;
        cin >> N;

        if (N == 0) break;

        cout << catalan[N] << '\n';
    }

    return 0;
}