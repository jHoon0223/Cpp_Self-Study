#include <iostream>
#include <string>

using namespace std;

int arr[100001];
int top = -1;

int main() {
    int N;
    cin >> N;

    while(N-->0) {
        string s;
        cin >> s;

        if (s == "push") {
            int n;
            cin >> n;
            arr[++top] = n;
        }
        else if (s == "pop") {
            if (top == -1) cout << -1 << endl;
            else cout << arr[top--] << endl;
        }
        else if (s == "size") {
            cout << top+1 << endl;
        }
        else if (s == "empty") {
            if (top == -1) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (s == "top") {
            if (top == -1) cout << -1 << endl;
            else cout << arr[top] << endl;
        }
    }

    return 0;
}