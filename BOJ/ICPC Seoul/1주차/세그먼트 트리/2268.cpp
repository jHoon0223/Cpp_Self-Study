#include <iostream>

#define MAX 1000001
#define TREE_HEIGHT MAX*4

using namespace std;

int N,M;

int arr[MAX];
long long segTree[TREE_HEIGHT];

long long init(int start, int end, int node) {
    if (start == end) 
        return segTree[node] = arr[start];

    int mid = (start + end) / 2;

    long long tmp_left = init(start, mid, node*2);
    long long tmp_right = init(mid+1, end, node*2+1);
    return segTree[node] = tmp_left + tmp_right;
}

long long subSum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) 
        return 0;

    if (left <= start && right >= end) 
        return segTree[node];

    int mid = (start + end) / 2;

    long long tmp_left = subSum(start, mid, node*2, left, right);
    long long tmp_right = subSum(mid+1, end, node*2 + 1, left, right);
    return tmp_left + tmp_right;
}

void update(int start, int end, int node, int targetIdx, long long val) {
    if (targetIdx > end || targetIdx < start)
        return ;

    segTree[node] += val;

    if (start == end)
        return ;

    int mid = (start + end) / 2;

    update(start, mid, node*2, targetIdx, val);
    update(mid+1, end, node*2+1, targetIdx, val);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        arr[i] = 0;
    }

    init(0, N-1, 1);

    while (M-->0) {
        int mode, a, b;

        cin >> mode >> a >> b;

        switch(mode) {
            case 0: {
                a--; b--;

                if (a > b) {
                    swap(a,b);
                }

                int total = subSum(0, N-1, 1, a, b);
                cout << total << '\n';

                break;
            }
            case 1: {
                a--;

                long long tmp = b - arr[a];
                arr[a] = b;
                update(0, N-1, 1, a, tmp);

                break;
            }
        }
    }

    return 0;
}