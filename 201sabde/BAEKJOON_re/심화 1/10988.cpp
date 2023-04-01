#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    string rev = str;
    reverse(rev.begin(), rev.end());

    if (!str.compare(rev)) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}