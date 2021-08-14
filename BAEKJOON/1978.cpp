#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int cnt = 0, cnt_tmp;
    for (int i = 0; i < N; i++) {
        int target = v[i];
        cnt_tmp = 0;

        if (target == 1) continue;
        if (target == 2) cnt++;

        for (int j = 2; j < target; j++) {
            if (target % j == 0)
                break;
            else
                cnt_tmp++;

            if (cnt_tmp == target-2)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}