#include <iostream>
#include <string>

using namespace std;

int main() {
    string s[5];

    for (int i=0; i<5; i++) {
        string a;
        cin >> a;
        s[i] = a;
    }

    for (int j=0; j<15; j++) {
        for (int i=0; i<5; i++) {
            if (j >= s[i].length()) continue;
            else cout << s[i][j];
            
            /*char c = s[i][j];

            if (c >= 48 && c <= 57) cout << c;
            else if (c >= 65 && c <= 90) cout << c;
            else if (c >= 97 && c <= 122) cout << c;
            else continue;*/
        }
    }

    return 0;
}