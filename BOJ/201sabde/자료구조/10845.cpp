#include <iostream>
#include <string>

using namespace std;

int arr[10001];
int front=0, back=0;

int main() {
    int N;
    cin >> N;

    while(N-->0) {
        string s;
        cin >> s;

        if (s == "push") {
            int n;
            cin >> n;

            arr[back] = n;
            back++;
        }
        else if (s == "pop") {
            if (front == back) cout << -1 << endl;
            else {
                cout << arr[front] << endl;
                front++;
            }
        }
        else if (s == "size") {
            cout << back-front << endl;
        }
        else if (s == "empty") {
            if (front == back) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (s == "front") {
            if (front == back) cout << -1 << endl;
            else cout << arr[front] << endl;
        }
        else if (s == "back") {
            if (front == back) cout << -1 << endl;
            else cout << arr[back-1] << endl;
        }
    }

    return 0;
}