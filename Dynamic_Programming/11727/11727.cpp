#include <iostream>
using namespace std;
int dp[1001];
int count_possible(int n) {
	if (n == 0) return 1;
	if (dp[n] != -1) return dp[n];
	if (n > 1)
		dp[n] = (count_possible(n - 2) % 10007 + count_possible(n - 2) % 10007 + count_possible(n - 1) % 10007) % 10007;
	else
		dp[n] = count_possible(n - 1) % 10007;
	return dp[n];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 1001; i++) {
		dp[i] = -1;
	}
	cout << count_possible(N) << endl;
	return 0;
}