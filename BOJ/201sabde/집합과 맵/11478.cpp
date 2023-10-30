#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        vector<string> v;

        for (int j=0; j<s.size()-i; j++) {
            string tmp = s.substr(j, 1+i);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        cnt += v.size();
    }
    
    cout << cnt << '\n';

    return 0;
}