#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> m;
    while(N-->0) {
        string s;
        cin >> s;
        m[s]++;
    }

    int max_res=0;
    for (map<string,int>::iterator it = m.begin(); it!=m.end(); it++) {
        max_res = max(max_res, it->second);
    }
    for (map<string,int>::iterator it = m.begin(); it!=m.end(); it++) {
        if (max_res == it->second) {
            cout << it->first << '\n';
            return 0;
        }
    }

    return 0;
}