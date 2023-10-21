#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int total = 0;
    for (int i=0; i<str.length(); i++) {
        char s = str.at(i);

        if (s=='A' || s=='B' || s=='C') total += 3;
        else if (s=='D' || s=='E' || s=='F') total += 4;
        else if (s=='G' || s=='H' || s=='I') total += 5;
        else if (s=='J' || s=='K' || s=='L') total += 6;
        else if (s=='M' || s=='N' || s=='O') total += 7;
        else if (s=='P' || s=='Q' || s=='R' || s=='S') total += 8;
        else if (s=='T' || s=='U' || s=='V') total += 9;
        else if (s=='W' || s=='X' || s=='Y' || s=='Z') total += 10;
    }
    cout << total << '\n';

    return 0;
}