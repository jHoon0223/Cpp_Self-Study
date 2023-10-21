#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T-->0) {
        int N;
        cin >> N;

        vector<pair<int,int>> v;
        for (int i=0; i<N; i++) {
            int a,b;
            cin >> a >> b;
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(), v.end());

        int cnt=1, standard=v[0].second;

        for (int i=1; i<N; i++)
            if (v[i].second < standard) {
                cnt++;
                standard = v[i].second;
            }

        cout << cnt << endl;
    }

    return 0;
}