#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100002

using namespace std;

vector<int> v;
int cnt[MAX];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N,T;
    cin >> N >> T;

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    while (T-->0) {
        fill(cnt, cnt+MAX, 0);

        int start,end;
        cin >> start >> end;
        start--; end--;

        vector<int> slice(v.begin() + start, v.begin() + end + 1);

        long long ans = 0;
        int size = slice[0];
        for (int i=0; i<slice.size(); i++) {
            size = max(size, slice[i]);

            cnt[slice[i]]++;
        }
        // for (int i=1; i<=size; i++) cout << cnt[i] << ' ';
        // cout << endl;
        for (int i=1; i<=size; i++) {
            ans += i * cnt[i] * cnt[i];
        }

        cout << ans << '\n';
    }

    return 0;
}