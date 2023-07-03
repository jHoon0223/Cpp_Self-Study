#include <iostream>
#include <string>

using namespace std;

int main() {
    int a;
    cin >> a;

    while(a-->0) {
        string s;
        cin >> s;

        if (s.length() >= 6 && s.length() <= 9) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}