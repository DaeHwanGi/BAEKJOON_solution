#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, value[100], dp[MAX];
int coin(int k) {
	if (k == 0) return 0;
	if (dp[k] != -1) return dp[k];

	int result=MAX;
	for (int i = 0; i < N; i++) {
		int current_val = value[i];
		if (k - current_val >= 0) result = min(result, coin(k - current_val) + 1);
	}
	dp[k] = result;
	cout << k << "," << dp[k] << endl;
	return result;
}
int main() {
	int K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> value[i];
	for (int i = 0; i <= K; i++)
		dp[i] = -1;

	int result = coin(K);
	if (result == MAX) cout << "-1" << endl;
	else cout << result << endl;
	return 0;
}