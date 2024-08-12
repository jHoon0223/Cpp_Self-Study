#include <iostream>

#define MAX 100005

using namespace std;

int G,P;
int dock[MAX];

int find(int a) {
    if (dock[a] == a) return a;

    return dock[a] = find(dock[a]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);

    //  더 작은 애를 루트로 해서 union
    if (a > b) dock[a] = b;
    else dock[b] = a;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    cin >> G >> P;

    for (int idx=0; idx<=G; idx++) {
        dock[idx] = idx;
    }

    int cnt=0;
    while (P-->0) {
        int target;
        cin >> target;

        int _target = find(target);

        if (_target == 0) break;

        uni(_target, _target-1);

        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}