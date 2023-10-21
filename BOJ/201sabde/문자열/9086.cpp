#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T-->0) {
        string s;
        cin >> s;

        cout << s.front() << s.back() << endl;
    }

    return 0;
}