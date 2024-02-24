#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);

    int A,B,C;
    cin >> A >> B >> C;

    int N = A*B*C;
    string s;
    s = to_string(N);

    int arr[10] = { 0 };
    for (int i=0; i<s.length(); i++) {
        arr[s[i]-48]++;
    }

    for (int aa : arr) cout << aa << '\n';

    return 0;
}