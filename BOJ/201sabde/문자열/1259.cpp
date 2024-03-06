#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (1) {
        string s;
        cin >> s;

        string ss = s;
        reverse(ss.begin(), ss.end());

        if (s.compare("0") == 0) break;
        else {
            if (s.compare(ss) == 0) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}