#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    while(N-->0) {
        int a,b;
        cin >> a >> b;

        cout << a+b << '\n';
    }

    return 0;
}