#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    char c;
    int N;
    cin >> N >> c;

    vector<string> v;
    for (int i=0; i<N; i++) {
        string s;        

        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end());

    int num = v.size();

    int total;
    if (c == 'Y') {
        total = num/1;
    }
    else if (c == 'F') {
        total = num/2;
    }
    else if (c == 'O') {
        total = num/3;
    }
    cout << total << endl;

    return 0;
}