#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100][100];
int M, N;
int dfs(int x, int y) {
	int nodes = 1;
	visited[x][y] = true;
	if (x - 1 >= 0 && visited[x - 1][y] == false) nodes += dfs(x - 1, y);
	if (x + 1 < N && visited[x + 1][y] == false) nodes += dfs(x + 1, y);
	if (y - 1 >= 0 && visited[x][y - 1] == false) nodes += dfs(x, y - 1);
	if (y + 1 < M && visited[x][y + 1] == false) nodes += dfs(x, y + 1);
	return nodes;
}
int main() {
	int K;
	cin >> M >> N >> K;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			visited[x][y] = false;
		}
	}
	for (int i = 0; i < K; i++) {
		int bottomleft_x, bottomleft_y, topright_x, topright_y;
		cin >> bottomleft_x >> bottomleft_y >> topright_x >> topright_y;
		for (int x = bottomleft_x; x < topright_x; x++)
			for (int y = bottomleft_y; y < topright_y; y++)
				visited[x][y] = true;
	}
	vector<int> result;
	int count = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (!visited[x][y]) {
				count++;
				result.push_back(dfs(x, y));
			}
		}
	}
	cout << count << endl;
	sort(result.begin(), result.end());
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}