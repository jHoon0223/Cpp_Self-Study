#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int num;
    cin >> num;

    int cnt=0;
    for (int i=0; i<n; i++) {
        if (v[i] == num) cnt++;
        else continue;
    }

    cout << cnt << endl;

    return 0;
}