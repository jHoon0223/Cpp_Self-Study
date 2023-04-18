#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S,T;
    cin >> S >> T;

    bool flag = false;
    while(!flag) {
        if (T.back() == 'A') T.pop_back();
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }

        if (T.compare(S) == 0) flag = true;
        
        if (T.length() < S.length()) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}