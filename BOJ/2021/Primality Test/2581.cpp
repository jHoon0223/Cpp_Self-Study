#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> v;
    for (int i = M; i <= N; i++) {
        int target = i;
        int cnt_tmp = 0;

        if (target == 1) continue;
        if (target == 2) v.push_back(2);

        for (int j = 2; j < target; j++) {
            if (target % j == 0)
                break;
            else
                cnt_tmp++;

            if (cnt_tmp == target-2) {
                v.push_back(target);
            }
        }
    }
    sort(v.begin(), v.end());
    
    if (v.empty())
        cout << -1;
    else {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) 
            sum += v[i];
        cout << sum << "\n" << v[0];
    }

    return 0;
}