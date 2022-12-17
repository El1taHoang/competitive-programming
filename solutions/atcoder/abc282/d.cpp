// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

bool dfs(int u, vector<vector<int>> &adj, vector<bool> &colour, vector<bool> &vis, vector<int>& component, int comp) {
	component[u] = comp;
	vis[u] = true;
	bool res = true;
	for (int v : adj[u]) {
		if (vis[v]) {
			if (colour[u] == colour[v]) {
				return false;
			}
		} else {
			colour[v] = !colour[u];
			res = res && dfs(v, adj, colour, vis, component, comp);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> component(n);
	vector<bool> colour(n);
	vector<bool> vis(n);
	vector<bool> vis_before(n);
	int comp = 0;
	for (int u = 0; u < n; u++) {
		if (!vis[u]) {
			if (!dfs(u, adj, colour, vis, component, comp++)) {
				cout << 0 << '\n';
				return 0;
			} else {
				int white = 0;
				int black = 0;
				int total = 0;
			}
		}
	}
	vector<int> white(n);
	vector<int> black(n);
	vector<int> comp_size(n);
	for (int i = 0; i < n; i++) {
		if (colour[i]) {
			black[component[i]]++;
		} else {
			white[component[i]]++;
		}
		comp_size[component[i]]++;
	}
	long long ans = 0;
	long long ans2 = 0;
	for (int i = 0; i < n; i++) {
		ans += 1LL * white[i] * black[i];
		ans2 += 1LL * comp_size[i] * (n - comp_size[i]);
	}
	ans2 /= 2;
	ans += ans2;
	ans -= m;
	cout << ans << '\n';
}
