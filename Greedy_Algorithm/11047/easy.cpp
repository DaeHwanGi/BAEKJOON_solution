#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int coin_zero() {
		int N, K;
		int ans = 0;
		cin >> N >> K;
		int *coin_arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> coin_arr[i];
		}
		for (int i = N - 1; i >= 0; i--) {
			ans += K / coin_arr[i];
			K = K % coin_arr[i];
		}
		cout << ans << endl;
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.coin_zero();
	return 0;
}