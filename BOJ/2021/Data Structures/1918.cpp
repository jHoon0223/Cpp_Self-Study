#include <iostream>
#include <stack>

using namespace std;

int whoseFisrt(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}   //char를 인자로 받아 우선순위 return 해주는 함수

int main() {
    string s;
    cin >> s;
    //중위표기식 s 입력

    stack<char> stk;
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 65 && s[i] <= 90) cout << s[i];
        //A~Z일 경우, 바로 출력
        else if (s[i] == '(') stk.push(s[i]);
        //'('일 경우, 스택에 push
        else if (s[i] == ')') {
            while(!stk.empty() && stk.top() != '(') {
                cout << stk.top();
                stk.pop();
            }   //스택의 top이 ')'이 아닐때 까지 pop하여 출력
            stk.pop();  //남아있는 '(' pop해서 제거
        }
        else {
            while (!stk.empty() && whoseFisrt(stk.top()) >= whoseFisrt(s[i])) {
                //스택의 top이 타겟으로 잡힌 string 인자보다 우선순위가 높거나 같을 경우,
                cout << stk.top();
                stk.pop();
            }   //스택의 top 원소 출력하고 pop
            stk.push(s[i]); //타겟으로 잡힌 string 인자를 다시 스택에 push
        }
    }
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }   //string의 끝까지 돌았으면, 스택에 남아있는 인자들 모두 pop하여 출력 / 후위표기식 완성

    return 0;
}