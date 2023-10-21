#include <iostream>
#include <string>

using namespace std;

int main() {
    char word[1001];

    string s;
    int a;

    cin >> s >> a;
    cout << s[a-1] << endl;

    return 0;
}