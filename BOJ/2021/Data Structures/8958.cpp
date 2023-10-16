#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)	{
		string n;
		cin >> n;

		int cnt = 0;
		int result = 0;
		for (int j = 0; j < n.length(); j++) {
			if (n[j] == 'O') {
				cnt++;
				result += cnt;
			}
			else
				cnt = 0;
		}
		cout << result << '\n';
	}

	return 0;
}