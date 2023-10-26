#include <iostream>
#include <math.h>

using namespace std;

int arr[16];

long long int f(int a) {
    if (a==1) return 3;
    else 
        return f(a-1) + pow(2, a-1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int result = pow(f(N), 2);
    cout << result << endl;

    return 0;
}