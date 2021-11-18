#include <iostream>

using namespace std;

void sort(int * arr, int n) {
    int tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    int* array = new int[N];
    for (int i = 0; i < N; i++)
        cin >> array[i];

    sort(array, N);

    for (int i = 0; i < N; i++)
        cout << array[i] << endl;

    return 0;
}