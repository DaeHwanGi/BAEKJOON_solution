#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, value[100], dp[MAX];

int main() {
	int K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> value[i];
	for (int i = 0; i <= K; i++)
		dp[i] = MAX;
	dp[0] = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			int current_coin = value[j];
			if(i+current_coin < MAX) dp[i + current_coin] = min(dp[i + current_coin], dp[i] + 1);
		}
	}
	if (dp[K] == MAX) cout << "-1" << endl;
	else cout << dp[K] << endl;
	return 0;
}