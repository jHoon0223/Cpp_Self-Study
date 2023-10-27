#include <iostream>
//#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    /*vector<string> v;

    while(N-->0) {
        string name, cmd;
        cin >> name >> cmd;

        if (!cmd.compare("enter")) {
            v.push_back(name);
        }
        else if (!cmd.compare("leave")) {
            v.erase(remove(v.begin(), v.end(), name),v.end());
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (string s : v) cout << s << '\n';*/
    //vector로 풀면 O(N^2)가 나와 시간초과 발생
    //set으로 풀자...

    set<string> s;
    
    while(N-->0) {
        string name, cmd;
        cin >> name >> cmd;

        if (!cmd.compare("enter")) s.insert(name);
        else s.erase(name);
    }
    //reverse(s.begin(), s.end());

    set<string>::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++) 
        cout << *rit << "\n";

    return 0;
}