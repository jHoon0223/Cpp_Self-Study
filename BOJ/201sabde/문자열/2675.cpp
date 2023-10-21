#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T-->0) {
        int R;
        string S, result;
        cin >> R >> S;

        for (int i=0; i<S.length(); i++)
            result.append(R, S[i]);

        cout << result << '\n';
    }
    
    return 0;
}