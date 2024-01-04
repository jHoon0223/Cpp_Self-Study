#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M;
    cin >> M;

    /*vector<int> v;

    while(M-->0) {
        string s;
        int n;

        cin >> s;

        if (s.compare("add") == 0) {
            cin >> n;
            v.push_back(n);
        }
        else if (s.compare("remove") == 0) {
            cin >> n;

            if (find(v.begin(), v.end(), n) == v.end()) continue;
            else v.erase(find(v.begin(), v.end(), n));
        }
        else if (s.compare("check") == 0) {
            cin >> n;
            
            if (find(v.begin(), v.end(), n) == v.end()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if (s.compare("toggle") == 0) {
            cin >> n;

            if (find(v.begin(), v.end(), n) == v.end()) v.push_back(n);
            else v.erase(find(v.begin(), v.end(), n));
        }
        else if (s.compare("all") == 0) {
            v.clear();

            for (int i=1; i<=20; i++) v.push_back(i);
        }
        else if (s.compare("empty") == 0) v.clear();
     }
     비트마스킹이 뭐길래 했는데,,, 시간초과가 날수밖에 없는 구조
     이따구로 풀면 안되는 문제다
     */

    int arr[21] = { 0 };
    while(M-->0) {
        string s;
        int n;
        cin >> s;

        if (s.compare("add") == 0) {
            cin >> n;
            arr[n] = 1;
        }
        else if (s.compare("remove") == 0) {
            cin >> n;
            arr[n] = 0;
        }
        else if (s.compare("check") == 0) {
            cin >> n;

            if (arr[n] == 1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (s.compare("toggle") == 0) {
            cin >> n;

            if (arr[n] == 1) arr[n] = 0;
            else arr[n] = 1;
        }
        else if (s.compare("all") == 0) {
            for (int i=0; i<21; i++) arr[i] = 1;
        }
        else if (s.compare("empty") == 0) {
            for (int i=0; i<21; i++) arr[i] = 0;
        }
    }

    return 0;
}