#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, value[2][MAX], dp[MAX][3];
int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
				cin >> value[i][j];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
				dp[i][j]=0;

		for (int i = 0; i < N; i++) {
			dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
			dp[i + 1][1] = max(dp[i + 1][1], max(dp[i][0], dp[i][2]) + value[0][i]);
			dp[i + 1][2] = max(dp[i + 1][2], max(dp[i][0], dp[i][1]) + value[1][i]);
		}

		cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
	}
	return 0;
}