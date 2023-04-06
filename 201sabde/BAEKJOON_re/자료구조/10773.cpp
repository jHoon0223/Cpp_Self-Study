#include <iostream>

using namespace std;

int stack[100001];
int top = 0;

int main() {
    int k;
    cin >> k;

    while(k-->0) {
        int a;
        cin >> a;

        if (a==0) {
            stack[--top] = 0;
        }
        else {
            stack[top++] = a;
        }
    }
    int total = 0;
    for (int i=0; i<top; i++) {
        total += stack[i];
    }
    cout << total << endl;

    return 0;
}