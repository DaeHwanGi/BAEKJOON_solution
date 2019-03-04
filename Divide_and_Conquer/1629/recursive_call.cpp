#include <iostream>

using namespace std;

typedef long long ll;

ll recursive(ll A, ll B, ll C) {
	cout << B << endl;
	if (B == 0) {
		return 1;
	}
	else if (B == 1) {
		return A%C;
	}
	else if (B % 2 == 0) { //Â¦¼ö
		ll temp = recursive(A, B / 2, C) % C;
		return temp*temp;
	}
	else { //È¦¼ö
		return (recursive(A, B / 2, C) % C)*(recursive(A, (B / 2) + 1, C) % C);
	}
}
class Solution {
public:
	int multiple() {
		ll A, B, C;
		ll ans;
		cin >> A >> B >> C;
		// A = A%C;
		ans = recursive(A, B, C)%C;
		cout << ans << endl;
		return 0;
	}
};
int main() {
	Solution solution = Solution();
	solution.multiple();
	return 0;
}