#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int camping() {
		int L, P, V;
		int cnt = 1;
		int ans = 0;
		cin >> L >> P >> V;
		while (L != 0) {
			ans = V / P*L + std::min(V%P, L);
			cout << "Case " << cnt << ": " << ans << endl;
			cin >> L >> P >> V;
			cnt++;
		}
		return 0;
	}
};

int main() {
	Solution solution = Solution();
	solution.camping();
	return 0;
}