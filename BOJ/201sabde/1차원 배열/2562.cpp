#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> origin, sorting;

    for (int i=0; i<9; i++) {
        int a;
        cin >> a;

        origin.push_back(a);
        sorting.push_back(a);
    }
    sort(sorting.begin(), sorting.end());
    
    int Max = sorting.back();
    cout << Max << '\n';

    if (find(origin.begin(), origin.end(), Max) != origin.end())
        cout << find(origin.begin(), origin.end(), Max) - origin.begin() + 1;

    return 0;
}