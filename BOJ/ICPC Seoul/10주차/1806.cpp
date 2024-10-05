#include <iostream>
#include <vector>

using namespace std;

int N,S;
vector<int> v;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i=0; i<N; i++) {
		int a;
        cin >> a;
        v.push_back(a);
	}

	int left = 0, right = 0;
	int sum = v.front();
	int len = N+1;

	while (left <= right && right < N) {
		if (sum < S) {
            right++;
            sum += v[right];
        }
		else {
            len = min(len, right - left + 1);
			sum -= v[left];
            left++;
		}
	}

	if (len == N+1) len = 0;
	cout << len << '\n';

	return 0;
}