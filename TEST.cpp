#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, score, p;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> score >> p;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	if (n == p && v[v.size() - 1] >= score) 
        cout << -1 << endl;
	else {
		int rank = 1;
		for (int i = 0; i < n; i++) {
			if (v[i] > score) rank++;
			else break;
		}
		cout << rank << endl;
	}
}