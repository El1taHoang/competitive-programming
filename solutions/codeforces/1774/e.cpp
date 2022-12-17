// Author: Aaron He
// Created: 17 December 2022 (Saturday)
// I found the bug in the last 7 minutes, but couldn't solve it in time...
// Rank 1126 (before system tests)
// Rank ? (after system tests)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

vector<vector<int>> adj;
vector<bool> has_1, has_2;
vector<int> max_depth_1, max_depth_2;

void dfs(int u, int from = -1) {
	for (int v : adj[u]) {
		if (v == from) continue;
		dfs(v, u);
		if (has_1[v]) {
			has_1[u] = true;
			max_depth_1[u] = max(max_depth_1[u], 1 + max_depth_1[v]);
		}
		if (has_2[v]) {
			has_2[u] = true;
			max_depth_2[u] = max(max_depth_2[u], 1 + max_depth_2[v]);
		}
	}
}

int max_d;
int dfs2(int u, int d, int from = -1) {
	if (!has_1[u] && !has_2[u]) {
		return 0;
	}
	int res = 0;
	if (!has_1[u] || !has_2[u]) {
		int new_d = d;
		if (has_1[u]) {
			new_d = max(d, min(max_d, max_depth_1[u]));
		} else {
			new_d = max(d, min(max_d, max_depth_2[u]));
		}
		res += 2 * (new_d - d);
		d = new_d;
	}
	for (int v : adj[u]) {
		if (v == from) continue;
		if (has_1[v] && has_2[v]) {
			res += 4 + dfs2(v, d, u);
		} else if (has_1[v] || has_2[v]) {
			if (d == 0) {
				assert(false);
				break;
			}
			int next = dfs2(v, max(0, d - 1), u);
			res += 2 + next;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	max_d = d;
	adj = vector<vector<int>>(n);
	has_1 = vector<bool>(n);
	has_2 = vector<bool>(n);
	max_depth_1 = vector<int>(n);
	max_depth_2 = vector<int>(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int m1;
	cin >> m1;
	vector<int> a(m1);
	for (int i = 0; i < m1; i++) {
		cin >> a[i];
		a[i]--;
		has_1[a[i]] = true;
		max_depth_1[a[i]] = 0;
	}
	int m2;
	cin >> m2;
	vector<int> b(m2);
	for (int i = 0; i < m2; i++) {
		cin >> b[i];
		b[i]--;
		has_2[b[i]] = true;
		max_depth_2[b[i]] = 0;
	}
	dfs(0);
	debug(has_1, has_2);
	cout << dfs2(0, d) << '\n';
}
