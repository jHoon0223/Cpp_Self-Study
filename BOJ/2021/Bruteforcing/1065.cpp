#include <iostream>

using namespace std;

int F(int n) {
    if (n>0 && n < 100)
        return n;
    else if (n == 1000)
        return 144;
    else {
        int cnt = 0;
        for (int i = 100; i <= n; i++) {
            int a = i/100, b = ((int)(i/10))%10, c = i%10;
            if (b-a == c-b)
                cnt++;
        }
        return cnt+99;
    }
}

int main() {
    int N;
    cin >> N;
    cout << F(N) << endl;

    return 0;
}