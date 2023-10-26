#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char input[10000];
    int B;
    int result = 0;

    scanf("%s %d", input, &B);      //문자와 진법을 입력받음

    int len = strlen(input);        //문자열 갯수 구하기

    for (int i = 0; i < len; i++) {
        int digit;
        if (input[i] >= '0' && input[i] <= '9') {
            digit = input[i] - '0';     //보기에는 숫자이지만 문자이므로 아스키 코드 연산을 이용해 숫자값을 구해야 됨
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            digit = input[i] - 'A' + 10;
        }
        
        result += digit * pow(B, len - 1 - i);      //진법 변환 식
    }

    printf("%d", result);

    return 0;
}