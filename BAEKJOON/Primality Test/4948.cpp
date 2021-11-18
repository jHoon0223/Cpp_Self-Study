#include <stdio.h>
#include <vector>

using namespace std;

const int MAX = 246913;

int main() {
    bool isPrime[MAX];

    for (int i = 0; i < MAX; i++)
        isPrime[i] = true;

    for (int i = 2; i < MAX; i++) {
        for (int j = i*2; j < MAX; j += i) {
            if (!isPrime[j]) continue;
            else isPrime[j] = false;
        }
    }

    while(1) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;
        else if (n == 1) {
            printf("1\n");
            continue;
        }
        else {
            int cnt = 0;

            for (int i = n+1; i <= 2*n; i++) {
                if (isPrime[i]) cnt++;
            }
            printf("%d\n", cnt);
        }
    }

    return 0;
}