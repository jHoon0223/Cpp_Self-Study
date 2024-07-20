#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int total;

void F(int x, int y, int size) {
    if (x==c && y==r) {
        cout << total << '\n';
        return ;
    }
    else if (c < x+size && r < y+size && x <= c && y <= r) {
        F(x, y, size/2);
        F(x+size/2, y, size/2);
        F(x, y+size/2, size/2);
        F(x+size/2, y+size/2, size/2);
    }
    else {
        total += size * size;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> r >> c;

    F(0,0,pow(2,N));

    return 0;
}