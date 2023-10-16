#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string white[8] = { {"WBWBWBWB"},
                    {"BWBWBWBW"},
                    {"WBWBWBWB"},
                    {"BWBWBWBW"},
                    {"WBWBWBWB"},
                    {"BWBWBWBW"},
                    {"WBWBWBWB"},
                    {"BWBWBWBW"} };
string black[8] = { {"BWBWBWBW"},
                    {"WBWBWBWB"},
                    {"BWBWBWBW"},
                    {"WBWBWBWB"},
                    {"BWBWBWBW"},
                    {"WBWBWBWB"},
                    {"BWBWBWBW"}, 
                    {"WBWBWBWB"} };
string Input[50];

int whiteCnt(int a, int b) {
    int cnt = 0;

    for (int i = a; i < a+8; i++)
        for (int j = b; j < b+8; j++)
            if (Input[i][j] != white[i-a][j-b]) cnt++;
    return cnt;
}
int blackCnt(int a, int b) {
    int cnt = 0;

    for (int i = a; i < a+8; i++)
        for (int j = b; j < b+8; j++)
            if (Input[i][j] != black[i-a][j-b]) cnt++;
    return cnt;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> Input[i];

    vector<int> v;
    for (int i = 0; i < N-7; i++) {
        for (int j = 0; j < M-7; j++) {
            v.push_back(whiteCnt(i, j));
            v.push_back(blackCnt(i, j));
        }
    }
    sort(v.begin(), v.end());
    cout << v[0];

    return 0;
}