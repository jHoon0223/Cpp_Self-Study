#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a,b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int A = stoi(a);
    int B = stoi(b);

    A > B ? cout << A << '\n' : cout << B << '\n';

    return 0;
}