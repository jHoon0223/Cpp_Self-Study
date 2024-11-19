#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int A,B,C;
    cin >> A >> B >> C;

    cout << A + B - C << '\n';
    
    string a = to_string(A);
    string b = to_string(B);
    string ab = a+b;

    cout << stoi(ab) - C << '\n';

    return 0;
}