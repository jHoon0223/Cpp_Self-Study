#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int total = 0;
    while(N-->0) {
        char a;
        cin >> a;
        total += (a-'0');
    }
    cout << total;

    return 0;
}