#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int A,B;
	cin >> A >> B;

	int asd = A*B;

	int total1;
	
	while(1) {
		int tmp = max(A,B) % min(A,B);

		if (tmp == 0) {
			total1 = min(A,B);
			break;
		}
		else {
			A = min(A,B);
			B = tmp;
		}
	}

	int total2 = asd/total1;
	cout << total1 << '\n' << total2 << '\n';

	return 0;
}