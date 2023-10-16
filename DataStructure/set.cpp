#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    multiset<int> ms;

    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(3);
    s.insert(5);
    s.insert(4);    //중복된 값이므로 set에 들어가지 않음

    ms.insert(1);
    ms.insert(2);
    ms.insert(4);
    ms.insert(3);
    ms.insert(5);
    ms.insert(4);   //중복된 값을 허용

    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << " ";

    cout << endl;

    for (multiset<int>::iterator iter = ms.begin(); iter != ms.end(); iter++)
        cout << *iter << " ";

    return 0;
}