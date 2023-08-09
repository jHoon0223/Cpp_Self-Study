#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;

    for (int i=0; i<10; i++) {
        int a;
        cin >> a;
        v.push_back(a%42);
    }
    sort(v.begin(), v.end());

    //unique : vector 내에서 중복된 값들을 가장 뒤로 보내는 레퍼런스
    
    //unique의 리턴값은 그 쓰레기값들의 맨 첫번째 위치
    //unique 레퍼런스의 리턴값과 erase를 이용하여 vector 내의 중복된 값들을 손쉽게 제거할 수 있다.
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size() << endl;

    return 0;
}