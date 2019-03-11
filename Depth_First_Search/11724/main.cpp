#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (!visited[next]) dfs(next);
	}
	return 0;
}
int main() {
	int N, M;
	cin >> N >> M;

	adj.resize(N);
	visited.resize(N);
	fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u = u - 1;
		v = v - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int component = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			component++;
			dfs(i);
		}
	}
	cout << component << endl;
	return 0;
}