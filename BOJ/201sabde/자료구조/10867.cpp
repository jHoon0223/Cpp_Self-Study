#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    while(N-->0) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());

    for (int i:v) cout << i << ' ';

    return 0;
}