#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i<3; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    int total;
    if (v[0]==v[1] && v[0]==v[2] && v[1]==v[2]) total = 10000+v[0]*1000;
    else if (v[0]==v[1]) total = 1000+v[0]*100;
    else if (v[0]==v[2]) total = 1000+v[0]*100;
    else if (v[1]==v[2]) total = 1000+v[1]*100;
    else total = v[2]*100;

    cout << total << endl;

    return 0;
}