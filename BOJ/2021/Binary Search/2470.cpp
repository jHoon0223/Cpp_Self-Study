#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int toAbsoluteValue(int a) {
    if (a < 0) return -a;
    return a;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int left = 0, right = N-1, total = v[left] + v[right];
    int tmpL = 0, tmpR = N-1, tmpTotal;

    while (tmpL < tmpR) {
        tmpTotal = v[tmpL] + v[tmpR];

        if (toAbsoluteValue(tmpTotal) < toAbsoluteValue(total)) {
            total = tmpTotal;
            left = tmpL;
            right = tmpR;
        }

        if (tmpTotal <= 0) tmpL++;
        else tmpR--;
    }
    cout << v[left] << " " << v[right];

    return 0;
}