#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int arr[26] = { 0 };
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);

    for (int i = 0; i < s.size(); i++) {
        int index = s[i]-97;
        arr[index]++;
    }

    vector<int> v;
    for (int i = 0; i < 26; i++) {
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end(), greater<>());
    if (v[0] == v[1])
        cout << '?' << endl;
    else {
        for (int i = 0; i < 26; i++) {
            if (v[0] == arr[i]) {
                cout << (char)(65+i);
                break;
            }
            else
                continue;
        }
    }

    return 0;
}