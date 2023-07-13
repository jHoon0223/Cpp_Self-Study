#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> v;
    int cnt=0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;

        if (a < x) {
            v.push_back(a);
            cnt++;
        }
        else continue;
    }

    for (int i=0; i<cnt; i++) cout << v[i] << ' ';

    return 0;
}