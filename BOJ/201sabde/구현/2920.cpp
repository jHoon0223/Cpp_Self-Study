#include <iostream>

using namespace std;

int main() {
    int arr[8];
    for (int i=0; i<8; i++) {
        cin >> arr[i];
    }

    bool ASCflag = false;
    bool DESflag = false;

    for (int i=0; i<7; i++) {
        if (arr[i] < arr[i+1]) {
            ASCflag = true;
        }
        else if (arr[i] > arr[i+1]) {
            DESflag = true;
        }
        else {
            cout << "mixed" << '\n';
            return 0;
        }
    }

    if (ASCflag == DESflag) cout << "mixed\n";
    else if (ASCflag) cout << "ascending\n";
    else if (DESflag) cout << "descending\n";

    return 0;
}