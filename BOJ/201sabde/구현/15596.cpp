#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (int tmp : a) ans += tmp;
	return ans;
}
