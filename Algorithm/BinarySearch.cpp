#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

// bool binarySearch(int target) {
//     int left = 0;
//     int right = v.size() - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;  // 중간 인덱스 계산
        
//         if (v[mid] == target) return true;  // target을 찾음
//         else if (v[mid] < target) left = mid + 1;  // target이 오른쪽에 있음
//         else right = mid - 1;  // target이 왼쪽에 있음
//     }
    
//     return false;  // target을 찾지 못함
// }

bool binarySearch(int target) {
    // lower_bound를 사용하여 target 이상의 첫 번째 위치를 찾고, 인덱스로 변환
    int index = lower_bound(v.begin(), v.end(), target) - v.begin();
    
    // 배열의 범위를 벗어나지 않고, 해당 위치의 값이 target과 같다면 target이 존재
    if (index < v.size() && v[index] == target) return true;
    else return false;
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

    flag = binarySearch(target);
    if (flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}