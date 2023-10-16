#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(9);
    array<int, 9> arr;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        arr[i] = a;
    }
    sort(v.begin(), v.end());

    int MAX = v.back();

    for (int i = 0; i < 9; i++) {
        if (arr[i] == MAX) {
            cout << MAX << endl;
            cout << i+1 << endl;
            break;
        }
        else
            continue;
    }

    return 0;
}