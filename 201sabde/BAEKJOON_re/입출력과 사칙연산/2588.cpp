#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;

    int one = b - 10*(b/10);
    int ten = (b - 100*(b/100) - b%10)/10;
    int hund = b/100;

    cout << a*one << endl;
    cout << a*ten << endl;
    cout << a*hund << endl;
    cout << a*b << endl;

    return 0;
}