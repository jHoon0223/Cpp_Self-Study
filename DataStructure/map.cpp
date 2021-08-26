#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    map<char, int> m;
    multimap<char, int> mm;

    m.insert(make_pair('a', 1));
    m.insert(make_pair('b', 2));
    m.insert(make_pair('b', 3));    //중복 허용 X
    m.insert(make_pair('d', 4));
    m.insert(make_pair('c', 5));
    m['e'] = 6; //가능

    mm.insert(make_pair('a', 1));
    mm.insert(make_pair('b', 3));
    mm.insert(make_pair('b', 2));   //중복 허용
    mm.insert(make_pair('d', 4));
    mm.insert(make_pair('c', 5));

    for (map<char,int>::iterator iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << "-" << iter->second << " ";

    cout << endl;

    for (multimap<char,int>::iterator iter = mm.begin(); iter != mm.end(); iter++)
        cout << iter->first << "-" << iter->second << " ";

    return 0;
}