// Author: Aaron He
// Created: 8 November 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;

int dfs(int u, vector<vector<int>> &adj, vector<int> &height, int h, int from = -1) {
	int cost = 0;
	for (int v : adj[u]) {
		cost += dfs(v, adj, height, h, u);
	}
	int cur_height = 1;
	for (int v : adj[u]) {
		cur_height = max(cur_height, height[v] + 1);
	}
	if (cur_height == h && u != 0 && from != 0) {
		cur_height = 0;
		cost++;
	}
	height[u] = cur_height;
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> adj(n);
		for (int i = 1; i <= n - 1; i++) {
			int p;
			cin >> p;
			p--;
			adj[p].push_back(i);
		}
		int l = 1, r = n;
		while (l < r) {
			int m = (l + r)/2;
			vector<int> height(n);
			if (dfs(0, adj, height, m) <= k) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << l << '\n';
	}
}
