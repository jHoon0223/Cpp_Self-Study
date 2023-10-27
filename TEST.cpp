#include <iostream>
#include <string>
#include <regex>

using namespace std;
 
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    std::string s = "C++17";
 
    std::string x = "17";
    std::string y = "20";
 
    s = std::regex_replace(s, std::regex(x), y);
 
    std::cout << s << std::endl;        // C++20
 
    return 0;
}