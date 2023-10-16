#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int diff, total = 2000000000;
    vector<int>::iterator front = v.begin(), back = v.begin()+1;
    while(front < v.end() && back < v.end()) {
        diff = *back - *front;
        if (diff == M) {
            total = M;
            break;
        }
        else if (diff > M) {
            total = min(total, diff);
            front++;
        }
        else back++;
    }
    printf("%d\n", total);

    return 0;
}