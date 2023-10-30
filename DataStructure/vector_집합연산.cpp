#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  // 반드시 정렬된 후 사용 가능
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b = {5, 6, 7, 8, 9};
  vector<int> result1(10);
  vector<int> result2(10);
  vector<int> result3(10);
  vector<int> result4(10);
  vector<int>::iterator iter;
  
  // sort(a.begin(), a.end());
  // sort(b.begin(), b.end());
  
  // 차집합 (A - B) - [1, 2, 3, 4]
  iter = set_difference(a, a+5, b, b+5, result1.begin());
  result1.resize(iter - result1.begin());
  
  // 차집합 (B - A) - [6, 7, 8, 9]
  iter = set_difference(b, b+5, a, a+5, result2.begin());
  result2.resize(iter - result2.begin());
  
  // 교집합 (A ∩ B) - [5]
  iter = set_intersection(a, a+5, b, b+5, result3.begin());
  result3.resize(iter - result3.begin());
  
  // 대칭 차집합 (A △ B) - [1, 2, 3, 4, 6, 7, 8, 9] (교집합을 제외하는 느낌)
  iter = set_symmetric_difference(a, a+5, b, b+5, result4.begin());
  result4.resize(iter - result4.begin());
  
  return 0;
}