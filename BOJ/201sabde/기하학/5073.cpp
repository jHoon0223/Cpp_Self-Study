#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while(1) {
        int a,b,c;
        cin >> a >> b >> c;

        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());

        if (a==0 && b==0 && c==0) break;

        if (v.back() >= v[0]+v[1]) cout << "Invalid\n";
        else if (a==b && a==c && b==c) cout << "Equilateral\n";
        else if (a==b) cout << "Isosceles\n";
        else if (b==c) cout << "Isosceles\n";
        else if (a==c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }

    return 0;
}