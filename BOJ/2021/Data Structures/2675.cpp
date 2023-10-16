#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T-->0) {
        int R;
        string s;
        cin >> R >> s;

        vector<char> v;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (int i = 0; i < R; i++)
                v.push_back(c);
        }

        for (int i = 0; i < v.size(); i++)
            cout << v[i];
        cout << endl;
    }

    return 0;
}