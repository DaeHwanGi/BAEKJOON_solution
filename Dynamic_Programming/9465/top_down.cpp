#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
int N, value[2][MAX], dp[MAX][3];
int sticker(int col, int status) {
	if (col == N) return 0;
	if (dp[col][status] != -1) return dp[col][status];
	// 아무것도 때지 않을때
	int result = sticker(col + 1, 0);
	// col의 위를 땔 때
	if (status != 1) result = std::max(result, sticker(col + 1, 1) + value[0][col]);
	// col의 아래를 땔 때
	if (status != 2) result = std::max(result, sticker(col + 1, 2) + value[1][col]);

	dp[col][status] = result;
	return result;
}
int main() {
	int T;
	
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < N; j++) {
				cin >> value[i][j];
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < 3; j++)
				dp[i][j] = -1;
		cout << sticker(0, 0) << endl;
	}
	return 0;
}