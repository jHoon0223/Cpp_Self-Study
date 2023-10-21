#include <iostream>

using namespace std;

int main() {
    int A,B;
    cin >> A >> B;

    int cnt = 0;
    while(1) {
        if (B%10 == 1) {
            B--;
            B /= 10;
            cnt++;
        }
        else if (B%2 == 0){
            B /= 2;
            cnt++;
        }
        else {
            cout << -1 << endl;
            return 0;
        }

        if (A==B) break;
        
        if (B<A) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt+1 << endl;

    return 0;
}