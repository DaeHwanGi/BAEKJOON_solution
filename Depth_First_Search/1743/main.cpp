#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int result;
int dfs(int pos) {
	int nodes = 1;
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (!visited[next]) nodes += dfs(next);
	}
	return nodes;
}
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	adj.resize(N*M);
	visited.resize(N*M);
	result = 0;
	fill(visited.begin(), visited.end(), true);
	while (K--) {
		int r, c;
		cin >> r >> c;
		r = r - 1;
		c = c - 1;
		int idx = r*M + c;
		visited[idx] = false;
		if (idx - M >= 0 && visited[idx - M] == false) {
			adj[idx].push_back(idx - M); //╩С
			adj[idx - M].push_back(idx);
		}
		if (idx + M < N*M && visited[idx + M] == false) {
			adj[idx].push_back(idx + M); //го
			adj[idx + M].push_back(idx);
		}
		if (idx - 1 >= r*M && visited[idx - 1] == false) {
			adj[idx].push_back(idx - 1); //аб
			adj[idx - 1].push_back(idx);
		}
		if (idx + 1 < (r + 1)*M && visited[idx + 1] == false) {
			adj[idx].push_back(idx + 1); //©Л
			adj[idx + 1].push_back(idx);
		}
	}
	for (int i = 0; i < N*M; i++) {
		if (!visited[i]) {
			result = max(result, dfs(i));
		}
	}
	cout << result << endl;
}