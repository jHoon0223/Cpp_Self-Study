#include <iostream>

using namespace std;

int main() {
    while(1) {
        int A, B;
        cin >> A >> B;
        
        if (A == 0 && B == 0)
            break;
        else
            cout << A+B << endl;
    }

    return 0;
}