#include <iostream>
using namespace std;
int dp[91][2];
int count_possible(int n, int last_status) {
	if (n == 1) return 1;
	if (dp[n][last_status] != -1) return dp[n][last_status];
	if (last_status == 0) {
		dp[n][last_status] = count_possible(n - 1, 0) + count_possible(n - 1, 1);
		return dp[n][last_status];
	}
	else {
		dp[n][last_status] = count_possible(n - 1, 0);
		return dp[n][last_status];
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 91; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	cout << count_possible(N, 1) << endl;
	return 0;
}