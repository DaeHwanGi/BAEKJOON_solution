#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][10] = { 0 };
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 10; i++) dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			int sum = 0;
			for (int k = 0; k <= j; k++) {
				sum += dp[i - 1][k] % 10007;
			}
			dp[i][j] = sum % 10007;
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) result += dp[N][i] % 10007;
	cout << result % 10007 << endl;
	return 0;
}