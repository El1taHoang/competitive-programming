// Author: Aaron He
// Created: 6 December 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

vector<long long> dist; // distance from representative node per component
vector<int> rep; // representative node in component
vector<bool> pos_cycle; // whether there is a cycle with non zero size (the answer is then infinity)
vector<vector<pair<int, int>>> adj;

void dfs(int u, int r, long long d) {
	rep[u] = r;
	dist[u] = d;
	for (auto &[v, w] : adj[u]) {
		if (rep[v] && d + w != dist[v]) {
			pos_cycle[rep[u]] = true;
			debug(u, v, d, w);
		}
		if (!rep[v]) {
			dfs(v, r, d + w);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	dist = vector<long long>(n + 1);
	rep = vector<int>(n + 1);
	pos_cycle = vector<bool>(n + 1);
	adj = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, -c);
	}
	for (int i = 1; i <= n; i++) {
		if (!rep[i]) {
			dfs(i, i, 0);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (rep[x] != rep[y]) {
			cout << "nan" << '\n';
		} else if (pos_cycle[rep[x]]) {
			cout << "inf" << '\n';
		} else {
			cout << dist[y] - dist[x] << '\n';
		}
	}
}
