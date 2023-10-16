#include <stdio.h>
#include <algorithm>

using namespace std;

int n[100001];

void BS(int target, int left, int right) {
    int mid;

    while (left <= right) {
        mid = (left+right) / 2;

        if (target == n[mid]) {
            printf("1\n");
            return;
        }
        else if (target < n[mid]) right = mid-1;
        else if (target > n[mid]) left = mid+1;
    }
    printf("0\n");
    return;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
    sort(n, n+N);

    int M;
    scanf("%d", &M);

    int tmp;
    for (int i = 0; i < M; i++) {
        scanf("%d", &tmp);
        BS(tmp, 0, N-1);
    }

    return 0;
}