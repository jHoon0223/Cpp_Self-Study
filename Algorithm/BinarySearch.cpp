#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool BinarySearch(int target, int left, int right) {
    int mid;

    while (left <= right) {
        mid = (left+right) / 2;

        if (target == v[mid]) return true;
        else if (target < v[mid]) right = mid-1;
        else if (target > v[mid]) left = mid+1;
    }
    return false;
}

int main(void) {
    int N;
    cout << "N >> ";
    cin >> N;

    for (int i = 0; i < N; i++) 
        v.push_back(i);

    int target;
    bool flag;
    cout << "target >> ";
    cin >> target;

    flag = BinarySearch(target, 0, v.size());
    if (flag) cout << "YES";
    else cout << "NO";

    return 0;
}