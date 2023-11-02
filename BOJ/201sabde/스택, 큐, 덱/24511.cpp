#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    bool flag[100001];
    for (int i=0; i<N; i++) cin >> flag[i];

    deque<int> dq;
    for (int i=0; i<N; i++) {
        int b;
        cin >> b;
        if (flag[i]==0) dq.push_back(b);
    }

    int c;
    cin >> c;
    
    for (int i=0; i<c; i++) {
        int num;
        cin >> num;

        dq.push_front(num);

        cout << dq.back() << ' ';
        dq.pop_back();
    }

    return 0;
}