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

    cout << v.front() << " " << v.back();

    return 0;
}