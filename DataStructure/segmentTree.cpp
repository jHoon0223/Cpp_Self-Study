#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long init(vector<long long> &v, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = v[start];
    }
    else {
        return tree[node] = init(v, tree, node*2, start, (start+end)/2) + init(v, tree, node*2+1, (start+end)/2+1, end);
    }
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;

    tree[node] = tree[node] + diff;
    
    if (start != end) {
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;

        v.push_back(a);
    }

    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);

    M += K;

    init(v, tree, 1, 0, N-1);

    while (M--) {
        int t1,t2,t3;
        cin >> t1;

        if (t1 == 1) {
            int t2;
            long long t3;
            cin >> t2 >> t3;

            t2--;
            long long diff = t3-v[t2];
            v[t2] = t3;

            update(tree, 1, 0, N-1, t2, diff);
        }
        else if (t1 == 2) {
            int t2, t3;
            cin >> t2 >> t3;

            t2--; t3--;

            cout << sum(tree, 1, 0, N-1, t2, t3) << '\n';
        }
    }

    return 0;
}