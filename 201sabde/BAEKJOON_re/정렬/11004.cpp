#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    vector<int> v;
    for (int i=0; i<a; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    printf("%d\n", v[b-1]);

    return 0;
}