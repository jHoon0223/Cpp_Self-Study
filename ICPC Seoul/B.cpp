#include <iostream>

using namespace std;

int arr[300001];
int sum[300001];
bool visited[300001];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int n; cin >> n;
    int case_b = 0;
    int case_g = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum[i] = arr[i] + sum[i - 1];
    }

    
    int maxSum = arr[0];
    int currentSum = arr[0]; 

    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }


}