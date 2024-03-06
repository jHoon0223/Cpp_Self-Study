#include <iostream>
using namespace std;

int main() {
	int N, result = 0;
	int temp, cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;

		for (int i = 1; i <= temp; i++) {
			if (temp%i == 0)
				cnt++;
		}
		if (cnt == 2)	//temp가 소수
			result++;
		cnt = 0;
	}
	cout << result << '\n';
}