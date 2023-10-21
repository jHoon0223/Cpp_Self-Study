#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int,string>> v;
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        v.push_back(make_pair(s.length(), s));
    }

    sort(v.begin(), v.end()); //vector 정렬
    v.erase(unique(v.begin(),v.end()), v.end()); //vector 정렬 후, 중복된 값 제거

    for (int i=0; i<v.size(); i++)
        cout << v[i].second << '\n';

    return 0;
}