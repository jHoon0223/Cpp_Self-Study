#include <iostream>

using namespace std;

int cnt;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }
    else if (N > 1022) {
        cout << -1;
        return 0;
    }
    else {
        for (long long i = 1; ; i++) {
            long long target = i;

            if (target < 10) {
                cnt++;
            }
            else {
                while(1) {
                    int tmp1 = target%10;
                    int tmp2 = (target/10)%10;

                    if (tmp1 >= tmp2)
                        break;

                    target /= 10;

                    if (target < 10) {
                        cnt++;
                        break;
                    }
                }
            }
            
            if (cnt == N) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}