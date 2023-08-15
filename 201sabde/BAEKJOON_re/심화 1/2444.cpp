#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int max = N-1;
    for (int a=0; a<N; a++) {
        for (int i=0; i<max; i++) cout << ' ';
        int star1 = (2*N-1) - max*2;
        for (int j=0; j<star1; j++) cout << '*';

        max--;
        cout << endl;
    }

    for (int b=0; b<N-1; b++) {
        int space = b+1;

        for (int i=0; i<space; i++) cout << ' ';
        int star2 = (2*N-1) - 2*space;
        for (int j=0; j<star2; j++) cout << '*';

        cout << endl;
    }

    return 0;
}