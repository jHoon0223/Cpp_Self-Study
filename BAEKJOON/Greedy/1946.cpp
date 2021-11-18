#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    while (T-->0) {
        int N, cnt = 1;
        cin >> N;

        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }   //벡터 구성

        //브루트포스 방식으로 각 인덱스 전수조사 -> 시간 초과 발생. 연산 횟수 최대 10B
        /*for (int i = 0; i < v.size(); i++) {
            pair<int,int> target = v[i];

            for (int j = 0; j < v.size(); j++) {
                if (target.first > v[j].first && target.second > v[j].second) {
                    cnt++;
                    v.erase(v.begin() + i);
                    i--;
                    break;
                }
            }

        }
        cout << N-cnt << '\n';*/

        sort(v.begin(), v.end());

        int target = v[0].second;
        for (int i = 1; i < v.size(); i++) {
            if (target > v[i].second) {
                cnt++;
                target = v[i].second;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}