#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    while(N-- > 0) {
        int A, B;
        cin >> A >> B;

        int total;
        for (int i = 1; ; i++) {
            if ((A*i)%B == 0) {
                total = A*i;
                break;
            }
            else continue;
        }
        cout << total << endl;
    }

    return 0;
}