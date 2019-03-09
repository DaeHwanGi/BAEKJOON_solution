#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int main() {
	int N, K;
	cin >> N >> K;

	if (K > N / 2) K = N - K;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			dp[i][j] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < (i / 2)+1; j++) {
			if (j == 0) dp[i][j] = 1;
			if (j > (i - 1) / 2) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][i - 1 - j];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}