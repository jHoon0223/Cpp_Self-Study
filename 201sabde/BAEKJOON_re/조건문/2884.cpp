#include <iostream>

using namespace std;

int main() {
    int h,m;
    cin >> h >> m;

    if (h==0) {
        if (m>=45) m-=45;
        else if (m<45) {
            h=23;
            m+=15;
        }
    }
    else {
        if (m>=45) m-=45;
        else if (m<45) {
            h--;
            m+=15;
        }
    }
    cout << h << ' ' << m << endl;

    return 0;
}