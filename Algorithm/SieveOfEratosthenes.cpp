#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

int main() {
    int n;
    cin >> n;

    vector<int> primeVector;
    bool isPrime[MAX];

    for (int i = 0; i < n; i++)
        isPrime[i] = true;

    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        else primeVector.push_back(i);

        for (int j = i*2; j <= n; j += i)
            isPrime[j] = false;
    }

    for (int i = 0; i < primeVector.size(); i++)
        cout << primeVector[i] << " ";

    return 0;
}