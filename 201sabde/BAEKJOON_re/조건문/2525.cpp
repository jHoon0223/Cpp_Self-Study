#include <iostream>

using namespace std;

int main() {
    int h,m,t;
    cin >> h >> m >> t;

    int ht, mt;
    ht = t/60;
    mt = t%60;

    h+=ht;
    m+=mt;

    if (m>=60) {
        h++;
        m-=60;
    }
    if (h>=24) h-=24;

    cout << h << ' ' << m << endl;

    return 0;
}