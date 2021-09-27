#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> v, int target, int low, int high) {
    int mid;

    if (low > high) return 0;
    else {
        mid = (low+high)/2;
        if (target == v[mid])
            return mid;
        else if (target < v[mid])
            return BinarySearch(v, target, low, mid-1);
        else if (target > v[mid])
            return BinarySearch(v, target, mid+1, high);
    }
}

int main(void) {
    vector<int> v;

    int N;
    cout << "N >> ";
    cin >> N;

    for (int i = 0; i < N; i++) 
        v.push_back(i);

    int target, index;
    cout << "target >> ";
    cin >> target;

    index = BinarySearch(v, target, 0, v.size());
    cout << index << " " << v[index];

    return 0;
}