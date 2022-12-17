#include <time.h>
#include <cassert>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num_blue_edges;
int blue_node;
void dfs(int node, vector<vector<int>> &adj, vector<map<int, int>> &edge_to_idx, vector<int> &color, vector<bool> &visited) {
	visited[node] = true;
	for (int neighbor : adj[node]) {
		int edge_idx = edge_to_idx[node][neighbor];
		if (!visited[neighbor]) {
			color[edge_idx] = 0;
			dfs(neighbor, adj, edge_to_idx, color, visited);
		} else {
			if (color[edge_idx] == -1) {
				color[edge_idx] = 1;
				num_blue_edges++;
				blue_node = node;
				assert(num_blue_edges <= 3);
			}
		}
	}
}
bool blue_cycle(int node, vector<vector<int>> &adj, vector<map<int, int>> &edge_to_idx, vector<int> &color, vector<bool> &visited, int before = -1) {
	visited[node] = true;
	bool ans = false;
	for (int neighbor : adj[node]) {
		int edge_idx = edge_to_idx[node][neighbor];
		if (color[edge_idx] == 1) {
			if (visited[neighbor]) {
				if (neighbor != before) {
					return true;
				}
			} else {
				ans = ans || blue_cycle(neighbor, adj, edge_to_idx, color, visited, node);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		bool redo = true;
		vector<vector<int>> adj(n);
		vector<map<int, int>> edge_to_idx(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			edge_to_idx[u][v] = i;
			edge_to_idx[v][u] = i;
		}
		int seed = 0;
		while (redo) {
			num_blue_edges = 0;
			seed++;
			srand(seed);
			vector<int> color(m, -1);
			vector<bool> visited(n);
			redo = false;
			dfs(rand() % n, adj, edge_to_idx, color, visited);
			if (num_blue_edges == 3) {
				vector<bool> visited2(visited.size());
				redo = blue_cycle(blue_node, adj, edge_to_idx, color, visited2, -1);
			}
			if (!redo) {
				for (int i = 0; i < m; i++) {
					cout << color[i];
				}
				cout << '\n';
			}
		}
	}
}

