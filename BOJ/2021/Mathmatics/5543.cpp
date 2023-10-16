#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());

    for (int i = 0; i < 2; i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    sort(v2.begin(), v2.end());

    int total = (v1[0] + v2[0]) - 50;
    cout << total << endl;

    return 0;
}