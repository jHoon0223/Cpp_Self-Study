#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int total = n;
    for (int i=1; i<n; i++) total += i;
    cout << total << endl;
    
    return 0;
}