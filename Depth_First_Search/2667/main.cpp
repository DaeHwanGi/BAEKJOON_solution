#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[25][25];
int N;
int dfs(int i, int j) {
	cout << i << "," << j << endl;
	int nodes = 1;
	visited[i][j] = true;
	if (i - 1 >= 0 && visited[i - 1][j] == false) nodes += dfs(i - 1, j);
	if (i + 1 < N && visited[i + 1][j] == false) nodes += dfs(i + 1, j);
	if (j - 1 >= 0 && visited[i][j - 1] == false) nodes += dfs(i, j - 1);
	if (j + 1 < N && visited[i][j + 1] == false) nodes += dfs(i, j + 1);

	return nodes;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == '0') visited[i][j] = true;
			else visited[i][j] = false;
		}
	}
	vector<int> result;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				count++;
				result.push_back(dfs(i, j));
			}
		}
	}
	cout << count << endl;
	sort(result.begin(), result.end());
	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << endl;
	return 0;
}