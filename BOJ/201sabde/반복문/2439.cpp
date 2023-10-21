#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i=1; i<=N; i++) {
        int space = N-i;
        int star = i;

        while(space-->0) cout << ' ';
        while(star-->0) cout << '*';
        cout << '\n';
    }

    return 0;
}