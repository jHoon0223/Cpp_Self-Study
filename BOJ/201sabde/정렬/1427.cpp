#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N.size(); i++) {
        v.push_back(N[i]);
    }
    sort(v.begin(), v.end(), greater<int>());

    for(int i:v) cout << i-48;

    return 0;
}