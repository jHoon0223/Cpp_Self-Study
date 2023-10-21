#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int array[26];
    fill_n(array, 26, -1);
    for (int i=0; i<s.length(); i++) {
        int idx = s[i]-97;
        if (array[idx] == -1) array[idx] = i;
        else continue;
    }
    for (int i:array) cout << i << ' ';

    return 0;
}