#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string PCK[100000];

int main() {
	cin.tie(0);
    cout.tie(0);
	ios::sync_with_stdio(0);

    int N,M;
	cin >> N >> M;

    map<string, int> m;
	for (int i = 0; i < N; i++) {
		cin >> PCK[i];
		m.insert(make_pair(PCK[i], i));
	}

	for (int i = 0; i < M; i++) {
        string ans;
		cin >> ans;

		// 1. 입력된 것이 숫자인 경우
		if (isdigit(ans[0]) != 0) {
            int idx;
			idx = stoi(ans) - 1;
			cout << PCK[idx] << "\n";
		}

		// 2. 입력된 것이 문자인 경우
		else {
			map<string, int>::iterator iter;
            iter = m.find(ans);
			cout << iter->second + 1 << "\n";
		}
	}

	return 0;
}