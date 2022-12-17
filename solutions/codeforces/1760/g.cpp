// Author: Aaron He
// Created: 21 November 2022 (Monday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

void dfs(int u, int avoid, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
	for (auto &[v, w] : adj[u]) {
		if (dist[v] == -1 && v != avoid) {
			dist[v] = dist[u] ^ w;
			dfs(v, avoid, adj, dist);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<vector<pair<int, int>>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}
		a--, b--;
		vector<int> dist_a(n, -1), dist_b(n, -1);
		dist_a[a] = 0;
		dist_b[b] = 0;
		dfs(a, b, adj, dist_a);
		dfs(b, -1, adj, dist_b);
		debug(dist_a, dist_b);
		sort(dist_a.begin(), dist_a.end());
		bool ans = false;
		for (int i = 0; i < n; i++) {
			if (i != b && dist_b[i] != -1) {
				auto it = lower_bound(dist_a.begin(), dist_a.end(), dist_b[i]);
				if (it != dist_a.end() && *it == dist_b[i]) {
					debug(i);
					ans = true;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}
