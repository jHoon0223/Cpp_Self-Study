#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    int total[50];
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        pair<int, int> target = v[i];
        for (int j = 0; j < N; j++) {
            if (target.first < v[j].first && target.second < v[j].second)
                cnt++;
        }
        total[i] = cnt+1;
    }

    for (int i = 0; i < N; i++)
        cout << total[i] << " ";

    return 0;
}