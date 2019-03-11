#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;

	Graph() : N(0) {}
	Graph(int n) : N(n) {
		adj.resize(N);
		visited.resize(N);
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList() {
		for (int i = 0; i<N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	void dfs() {
		fill(visited.begin(), visited.end(), false);
		dfs(0);
	}
	int dfsAll() {
		int components = 0;
		for (int i = 0; i<N; i++) {
			if (!visited[i]) {
				//cout << "-- new DFS begins --" << endl;
				dfs(i);
				components++;
			}
		}
		return components;
	}
private:
	void dfs(int curr) {
		visited[curr] = true;
		//cout << "node " << curr << " visited" << endl;
		for (int next : adj[curr])
			if (!visited[next]) dfs(next);
	}
};

int main() {
	int T, M, N, K, x, y, idx;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		Graph g(M*N);
		fill(g.visited.begin(), g.visited.end(), true);
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			idx = y*M + x;
			g.visited[idx] = false;
			if (idx - M >= 0 && g.visited[idx - M] == false) //╩С
				g.addEdge(idx, idx - M);
			if (idx + M < M*N && g.visited[idx + M] == false) //го
				g.addEdge(idx, idx + M);
			if (idx - 1 >= y*M && g.visited[idx - 1] == false) //аб
				g.addEdge(idx, idx - 1);
			if (idx + 1 < (y + 1)*M && g.visited[idx + 1] == false) //©Л
				g.addEdge(idx, idx + 1);
		}
		cout << g.dfsAll() << endl;

	}
}