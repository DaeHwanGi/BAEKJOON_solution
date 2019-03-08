#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll dp[101][10];
int main() {
	cin >> N;
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			int result = 0;
			if (j == 0) result = dp[i - 1][j + 1] % 1000000000;
			else if (j == 9) result = dp[i - 1][j - 1] % 1000000000;
			else result = (dp[i - 1][j + 1] % 1000000000 + dp[i - 1][j - 1] % 1000000000) % 1000000000;
			dp[i][j] = result;
		}
	}
	ll sum = 0;
	for (int i = 0; i < 10; i++)
		sum += dp[N][i] % 1000000000;
	cout << sum % 1000000000 << endl;
	return 0;
}