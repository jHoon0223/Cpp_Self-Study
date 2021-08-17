#include <iostream>

using namespace std;

string s;
int len;

bool F(int a) {
    for (int i = 0; a+i < len-1-i; i++) {
        if (s[a+i] != s[len-1-i])
            return false;
    }
    return true;
}

int main() {
    cin >> s;
    len = s.size();

    int cnt = 0;
    for (int i =0; i < len; i++) {
        if (F(i)) {
            cnt = len + i;
            break;
        }            
    }

    cout << cnt;

    return 0;
}