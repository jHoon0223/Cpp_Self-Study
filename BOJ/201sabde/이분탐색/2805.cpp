#include <iostream>
#include <algorithm>

#define MAX 1000002

using namespace std;

long long arr[MAX];

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    long long N,M;
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr+N);

    long long start=0, end=arr[N-1], mid;
    long long total = 0;

    while(start <= end){
        long long sum = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < N ; i++){
            long long tmp = arr[i] - mid;

            if(tmp > 0) sum += tmp;
        }

        if(sum >= M){
            start = mid + 1;
            // mid 이후로 범위 바꿔서 다시 탐색

            if(mid > total) total = mid;
        }
        else end = mid - 1;
        //  mid 전으로 범위 바꿔서 다시 탐색
    }

    cout << total << '\n';

    return 0;
}