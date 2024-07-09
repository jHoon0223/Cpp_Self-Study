#include <iostream>
#include <climits>

#define MAX 100001
#define TREE_HEIGHT MAX*4

using namespace std;

int N,M;

int arr[MAX];
long long segTree[TREE_HEIGHT];
long long minTree[TREE_HEIGHT];

long long init(int start, int end, int node) {
    if (start == end) {
        minTree[node] = arr[start];
        return segTree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    long long tmp_left = init(start, mid, node*2);
    long long tmp_right = init(mid+1, end, node*2 + 1);
    minTree[node] = min(minTree[node*2], minTree[node*2 + 1]);
    return segTree[node] = tmp_left + tmp_right;
}

int SOL(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return INT_MAX;
    }

    if (left <= start && right >= end) {
        return minTree[node];
    }

    int mid = (start + end) / 2;

    int tmp_left = SOL(start, mid, node*2, left, right);
    int tmp_right = SOL(mid+1, end, node*2 + 1, left, right);
    return min(tmp_left, tmp_right);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    init(0, N-1, 1);

    for (int i=0; i<M; i++) {
        int left, right;
        cin >> left >> right;

        left--; right--;

        int total = SOL(0, N-1, 1, left, right);
        cout << total << '\n';
    }

    return 0;
}