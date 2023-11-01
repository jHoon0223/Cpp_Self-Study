#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> v;
    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    stack<int> st;
    int cnt=0;
    for (int i=1; i<=N; i++) {
        while(1) {
            if (!v.empty() && v.front() == i) {
                v.erase(v.begin());
                cnt++;
                break;
            }
            else if (!st.empty() && st.top() == i) {
                st.pop();
                cnt++;
                break;
            }
            else {
                if (!v.empty()) {
                     st.push(v.front());
                    v.erase(v.begin());
                }
                else {
                    break;
                }
            }
        }
    }
    cnt==N ? cout << "Nice\n" : cout << "Sad\n";

    return 0;
}