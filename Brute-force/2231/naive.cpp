#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int decomp_sum() {
		int sum, ith_sum;
		cin >> sum;

		for (int i = 0; i < sum; i++) {
			int temp = i;
			ith_sum = i;
			while (temp % 10 != 0) {
				ith_sum += temp % 10;
				temp = temp / 10;
			}
			if (ith_sum == sum) {
				cout << i << endl;
				break;
			}
		}
		cout << '0' << endl;
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.decomp_sum();
	return 0;
}