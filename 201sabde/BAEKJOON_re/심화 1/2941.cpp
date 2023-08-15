#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    string s;
    cin >> s;

    //if (s.find("dz=") != string::npos)
    s = regex_replace(s, regex("dz="), "a");
    s = regex_replace(s, regex("c="), "a");
    s = regex_replace(s, regex("c-"), "a");
    s = regex_replace(s, regex("d-"), "a");
    s = regex_replace(s, regex("lj"), "a");
    s = regex_replace(s, regex("nj"), "a");
    s = regex_replace(s, regex("s="), "a");
    s = regex_replace(s, regex("z="), "a");

    cout << s.length() << endl;

    return 0;
}