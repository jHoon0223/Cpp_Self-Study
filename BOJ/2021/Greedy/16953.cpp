#include <iostream>

using namespace std;

int main() {
    long long A, B, cnt = 0;
    cin >> A >> B;

    bool flag = false;

    while(B >= A) {
        if (A == B) {
            flag = true;
            break;
        }
        if (B%10 == 1) {
            B /= 10;
            cnt++;
        }
        else if (B%2 == 0) {
            B /= 2;
            cnt++;
        }
        else break;
    }
    flag ? cout << cnt+1 : cout << -1;

    return 0;
}