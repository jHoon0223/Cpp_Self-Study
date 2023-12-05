#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;

    int sum = a+b+c;
    if (sum != 180) {
        cout << "Error\n";
        return 0;
    }
    else {
        if (a==b && b==c && a==c) cout << "Equilateral\n";
        else if (a==b) cout << "Isosceles\n";
        else if (b==c) cout << "Isosceles\n";
        else if (a==c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }

    return 0;
}