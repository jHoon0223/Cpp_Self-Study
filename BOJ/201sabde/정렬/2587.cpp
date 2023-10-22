#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    int sum = 0;

    for (int i=0; i<5; i++) {
        int a;
        cin >> a;
        sum += a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int avg = sum / 5;
    cout << avg << '\n' << v[2] << endl;

    return 0;
}