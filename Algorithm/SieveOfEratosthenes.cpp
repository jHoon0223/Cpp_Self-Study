#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(int n) {
    // n까지의 숫자가 소수인지 여부를 저장하는 벡터
    vector<bool> isPrime(n + 1, true);

    // 0과 1은 소수가 아니므로 false로 설정
    isPrime[0] = isPrime[1] = false;

    // 2부터 시작하여 소수 여부를 판별
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            // i의 배수들은 소수가 아니므로 false로 설정
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 소수 출력
    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the upper limit to find primes: ";
    cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}