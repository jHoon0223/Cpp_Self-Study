#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool arr[100][100] = { false, };
    while(N-->0) {
        int x,y;
        cin >> x >> y;

        for (int i=x-1; i<x+9; i++) {
            for (int j=y-1; j<y+9; j++) {
                arr[i][j] = true;
            }
        }
    }

    int total=0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (arr[i][j] == true) total++;
            else continue;
        }
    }

    cout << total << endl;

    return 0;
}