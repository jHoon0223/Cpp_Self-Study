#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());

    int total;
    if (a==b && b==c && a==c) total = v[0] * 3;
    else if (v[0]+v[1] > v[2]) total = a+b+c;
    else total = 2*(v[0]+v[1]) - 1;

    cout << total << endl;

    return 0;
}