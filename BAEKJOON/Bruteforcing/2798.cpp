#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v, answer;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    //sort(v.begin(), v.end());

    /*for (int i = 0; i < N; i++)
        cout << v[i] << " ";

    cout << endl;*/

    int size = (N*(N-1)*(N-2)) / 6;
    
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            for (int k = j+1; k < N; k++)
                answer.push_back(v[i] + v[j] + v[k]);
    sort(answer.begin(), answer.end());

    /*for (int i = 0; i < size; i++)
        cout << answer[i] << " ";*/

    if (answer[0] == M)
        cout << answer[0];
    else {
        for (int i = 1; i < size; i++) {
            if (answer[i] > M) {
                cout << answer[i-1];
                break;
            }
            else if (answer[i] == M) {
                cout << answer[i];
                break;
            }
        }
    }

    return 0;
}