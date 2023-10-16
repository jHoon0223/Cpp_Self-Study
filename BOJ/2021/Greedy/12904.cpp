#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    bool flag = false;
    int lenS = S.length(), lenT = T.length();

    while (lenS <= lenT) {
        if (S == T) {
            flag = true;
            break;
        }
        if (T.back() == 'A') T.pop_back();
        else {
            T.pop_back();
            reverse(T.begin(), T.end());     
        }
        lenS = S.length();
        lenT = T.length();
    }

    flag ? cout << 1 : cout << 0;

    return 0;
}