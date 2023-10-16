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

    int total = 0, tmp;
    vector<int> time;
    for (int i = 0; i < N; i++) {
        tmp = 0;
        for (int j = 0; j <= i; j++)
            tmp += v[j];
        time.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
        total += time[i];

    cout << total;

    return 0;
}