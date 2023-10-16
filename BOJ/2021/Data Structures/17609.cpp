#include <iostream>
#include <string>

using namespace std;

/*int F(string s) {
    int len = s.length();
    string::iterator front = s.begin(), back = --s.end();
    bool flag = true;

    int t;
    len%2 == 0 ? t = len/2 : t = len/2 + 1;

    while (t-- > 0) {
        if (*front != *back) {
            if (*(front+1) == *back && flag) {
                flag = false;
                front++;
                continue;
            }
            else if (*front == *(back-1) && flag) {
                flag = false;
                back--;
                continue;
            }
            else if (!flag) return 2;
        }
        front++;
        back--;
    }
    if (flag) return 0;
    
    return 1;
}*/

bool isF(string s) {
    string::iterator front = s.begin(), back = --s.end();
    int len = s.length(), t;

    len%2 == 0 ? t = len/2 : t = len/2 + 1;

    while (t-- > 0) {
        if (*front != *back) return false;

        front++;
        back--;
    }
    return true;
}
bool isLF(string s) {
    string::iterator front = s.begin(), back = --s.end();
    int len = s.length(), cnt = 0;

    while (front <= back) {
        if (*front != *back) {
            cnt++;
            front++;
            continue;
        }
        if (cnt > 1) return false;

        front++;
        back--;
    }
    return true;
}
bool isRF(string s) {
    string::iterator front = s.begin(), back = --s.end();
    int len = s.length(), cnt = 0;

    while (front <= back) {
        if (*front != *back) {
            cnt++;
            back--;
            continue;
        }
        if (cnt > 1) return false;

        front++;
        back--;
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    while(T-- > 0) {
        string s;
        cin >> s;

        if (isF(s)) cout << 0 << '\n';
        else if (isLF(s) || isRF(s)) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}