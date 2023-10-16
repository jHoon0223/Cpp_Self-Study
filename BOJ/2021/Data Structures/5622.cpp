#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c >= 65 && c <= 67)
            total += 3;
        else if (c >= 68 && c <= 70)
            total += 4;
        else if (c >= 71 && c <= 73)
            total += 5;
        else if (c >= 74 && c <= 76)
            total += 6;
        else if (c >= 77 && c <= 79)
            total += 7;
        else if (c >= 80 && c <= 83)
            total += 8;
        else if (c >= 84 && c <= 86)
            total += 9;
        else if (c >= 87 && c <= 90)
            total += 10;
    }
    cout << total;

    return 0;
}