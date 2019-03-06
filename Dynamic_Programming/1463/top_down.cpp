#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int N;
	vector<int> cnt_mem;
public:
	Solution() {
		cin >> N;
		cnt_mem.resize(N + 1, -1);
	}
	int make_one() {
		for (int i = 1; i <= N; i++) {
			dp(i);
		}
		cout << cnt_mem[N] << endl;
		return 0;
	}
	int dp(int n) {
		if (n == 1) return 0;
		if (cnt_mem[n] != -1) return cnt_mem[n];

		int min_cnt = dp(n - 1) + 1;
		if (n % 3 == 0) min_cnt = std::min(min_cnt, dp(n / 3) + 1);
		if (n % 2 == 0) min_cnt = std::min(min_cnt, dp(n / 2) + 1);
		cnt_mem[n] = min_cnt;
		return min_cnt;
	}
};
int main() {
	Solution solution = Solution();
	solution.make_one();
	return 0;
}