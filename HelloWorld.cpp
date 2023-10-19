#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a;
    cin >> a;

    vector<int> v;

    for (int i=0; i<a; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    return 0;
}