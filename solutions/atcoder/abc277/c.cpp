// Author: Aaron He
// Created: 12 November 2022 (Saturday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs(v, adj, vis);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> f;
	vector<pair<int, int>> edges;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		f.push_back(u);
		f.push_back(v);
		edges.emplace_back(u, v);
	}
	f.push_back(1);
	sort(f.begin(), f.end());
	f.resize(unique(f.begin(), f.end()) - f.begin());
	debug(f);
	vector<vector<int>> adj(f.size());
	for (auto& [u, v] : edges) {
		int i = lower_bound(f.begin(), f.end(), u) - f.begin();
		int j = lower_bound(f.begin(), f.end(), v) - f.begin();
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	vector<bool> vis(f.size());
	dfs(0, adj, vis);
	int ans = 1;
	for (int i = 0; i < f.size(); i++) {
		if (vis[i]) {
			ans = max(ans, f[i]);
		}
	}
	cout << ans << '\n';
}
