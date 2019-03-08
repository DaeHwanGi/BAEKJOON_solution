#include <iostream>
using namespace std;
typedef long long ll;
ll dp[1000001];
ll count_possible(int n) {
	if (n == 0) return 1;
	if (dp[n] != -1) return dp[n];
	if (n >= 2)
		dp[n] = (count_possible(n - 2) % 15746 + count_possible(n - 1) % 15746) % 15746;
	else
		dp[n] = count_possible(n - 1) % 15746;
	return dp[n];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 1000001; i++) {
		dp[i] = -1;
	}
	cout << count_possible(N) << endl;
	return 0;
}