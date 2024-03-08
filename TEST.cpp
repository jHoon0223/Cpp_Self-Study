#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n*factorial(n-1);
}

int main() {
	int N,K;
	cin >> N >> K;

	int total = factorial(N) / (factorial(K) * factorial(N-K));
	cout << total << '\n';

	return 0;
}