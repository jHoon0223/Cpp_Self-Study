#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int bag[101][100001];
vector<pair<int, int>> item;

void dp() {
	for (int limit = 1; limit <= K; limit++) {
		for (int i_num = 1; i_num <= N; i_num++) {
			if (limit < item[i_num].first)
				bag[i_num][limit] = bag[i_num - 1][limit];
			else
				bag[i_num][limit] = max(bag[i_num - 1][limit - item[i_num].first] + item[i_num].second, 
                                        bag[i_num - 1][limit]);
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	cin >> N >> K;
	item.push_back(make_pair(0,0));

	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;

		item.push_back(make_pair(W,V));
	}
	
	dp();

	cout << bag[N][K] << '\n';

    return 0;
}