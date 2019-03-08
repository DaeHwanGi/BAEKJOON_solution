#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[100001];
vector<int> num_vec;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++) dp[i] = 100000;
	int valid_num = 1;
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; pow(j,2) <= N; j++) {
			if (i + j*j <= N) dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
		}
	}
	cout << dp[N] << endl;
	return 0;
}