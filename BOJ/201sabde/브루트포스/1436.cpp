#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;

    int cnt = 0;

    for (int i=0; ; i++) {
        string s = to_string(i);

        if (s.find("666") != string::npos) {
            int num = stoi(s);
            v.push_back(num);
            cnt++;
        }

        if (cnt==N) break;
    }

    cout << v[N-1] << endl;

    return 0;
}