// #include <iostream>
// #include <queue>

// using namespace std;

// int main() {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     //오름차순으로 정렬기준 변경

//     //원소 삽입
//     pq.push(4);
//     pq.push(7);
//     pq.push(3);
//     pq.push(1);
//     pq.push(10);
//     //가장 작은 값이 top에 오도록 자동으로 정렬된다

//     cout << pq.size() << "\n"; // 5

//     while (!pq.empty()) {
//         cout << pq.top() << " "; // 1 3 4 7 10
//         pq.pop();
//     }

//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> pq;

  // 음수로 변환해서 원소 삽입
  pq.push(-4);
  pq.push(-7);
  pq.push(-3);
  pq.push(-1);
  pq.push(-10);

  cout << pq.size() << "\n"; // 5

  // 절댓값이 작은 원소부터 출력되도록 (오름차순)
  while (!pq.empty()) {
      cout << -pq.top() << " "; // 1 3 4 7 10
      pq.pop();
  }

  return 0;
}