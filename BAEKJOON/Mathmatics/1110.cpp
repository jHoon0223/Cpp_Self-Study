#include <iostream>

using namespace std;

int main() {
    int N, cnt = 0;
    cin >> N;

    int n = N;
    while(1) {
        int ten = n/10, one = n%10;
        int temp = (ten + one)%10;
        n = one*10 + temp;
        
        cnt++;

        if (n == N)
            break;
    }
    cout << cnt;

    return 0;
}