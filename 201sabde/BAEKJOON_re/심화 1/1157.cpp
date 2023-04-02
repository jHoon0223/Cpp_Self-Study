#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++)
        s[i] = tolower(s[i]);
    //소문자 변환
    
    int array[26] = { 0 }, array_sort[26] = { 0 };
    for (int i=0; i<s.length(); i++) {
        int idx = s[i]-97;
        array[idx]++;
        array_sort[idx]++;
    }

    //for (int i:array) cout << i << ' ';

    sort(array_sort, array_sort+26);

    int Max = array_sort[25];
    vector<int> v;
    for (int i=0; i<26; i++) {
        if (Max == array[i])
            v.push_back(i);
    }

    if (v.size() == 1) printf("%c\n", (char)v[0]+65);
    else cout << "?\n";

    return 0;
}