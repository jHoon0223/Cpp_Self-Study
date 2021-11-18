#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector<long long> v;
    for (int i = 0; i < K; i++) {
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long left = 1;
    long long right = v.back();
    long long mid = 0, cnt;
    if (N == 1) cout << v[0];
    else {
        while(left <= right || cnt < N) {
            mid = (long long)((left+right) / 2);
            cnt = 0;
            for (int i = 0; i < K; i++)
                cnt += v[i] / mid;
            
            if (cnt >= N) left = mid+1;
            else if (cnt < N) right = mid-1;
        }
            cout << mid;
    }

    return 0;
}