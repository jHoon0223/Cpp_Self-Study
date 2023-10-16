#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<pair<int, bool>> v;
    for (int i = 0; i < 26; i++)
        v.push_back(make_pair(-1, false));

    for (int i = 0; i < s.length(); i++) {
        int target = s[i] - 97;
        if (v[target].second == false) {
            v[target].first = i;
            v[target].second = true;
        }
        else
            continue;
    }

    for (int i = 0; i < 26; i++)
        cout << v[i].first << " ";

    return 0;
}